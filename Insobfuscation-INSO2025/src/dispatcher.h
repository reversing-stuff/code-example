#ifndef DISPATCHER_H
#define DISPATCHER_H

#include "handler.h"
#include "vm.h"

class Dispatcher {
private:
    static inline std::unique_ptr<OpcodeHandler> opcodeTable[256] = {nullptr};

public:

    static void registerOpcode(VM::OPCODE opcode, std::unique_ptr<OpcodeHandler> handler) {
        if (opcodeTable[opcode] == nullptr) {
            opcodeTable[opcode] = std::move(handler);
        }
    }

    ~Dispatcher() {
        for (auto& handler : opcodeTable) {
            // If any handlers are left, this will delete them (handled by unique_ptr automatically)
            handler.reset();
        }
    }


    static void execute(VM* context) {
        OpcodeHandler* handler = nullptr;
        const std::vector<uint8_t>* row;
        const uint8_t* ptr;
        VM::OPCODE op;
        context->setLip(context->shuffling_map.find(context->getInstructionCpt())->second.first);
        context->setKey(context->shuffling_map.find(context->getInstructionCpt())->second.second);
        row = &(context->bytearrayPtr->at(context->getLip()));
        if (context->getRip() < row->size()) {
            ptr = row->data();
            op = static_cast<VM::OPCODE>(ptr[context->getRip()] ^ context->getKey());
        } else {
            exit(-1);
        }
        registerOpcode(VM::OPCODE::MOV, std::make_unique<MOVDispatcher>());
        registerOpcode(VM::OPCODE::MOVD, std::make_unique<MOVDupDispatcher>());
        registerOpcode(VM::OPCODE::CALL_OUT, std::make_unique<CALLOutHandler>());
        while (!context->getIsFinished()) {  // Use a loop instead of recursion
            handler = opcodeTable[op].get();
            if (!handler) {
                exit(-1);  // Stop execution if no valid handler is found
            }

            handler->execute(context);

            row = &(context->bytearrayPtr->at(context->getLip()));
            if (context->getRip() < row->size()) {
                ptr = row->data();
                op = static_cast<VM::OPCODE>(ptr[context->getRip()] ^ context->getKey());
            } else {
                exit(-1);
            }
        }
    }
};
#endif //DISPATCHER_H
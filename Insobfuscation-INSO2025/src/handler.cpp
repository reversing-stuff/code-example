#include "handler.h"
#include "dispatcher.h"
#include "vm.h"
#include <iostream>
#include <map>
#include <memory>
#include <vector>
#include <cstring>
#include <random>
#include <fstream>
#include <algorithm>

void EndHanlder::execute(VM* context) {
    //printf("END\n");
    context->setIsFinished();
}


void EndDuppHanlder::execute(VM* context) {
	    //printf("END\n");
	    context->setIsFinished();
	}


void JNZHandler::execute(VM* context) {
	    //printf("JNZ\n");
	    const std::vector<uint8_t>* row = &(context->bytearrayPtr->at(context->getLip()));
	    const uint8_t* ptr = row->data();
	    uint64_t rip = context->getRip();
	    context->setRip(context->getRip()+1);
	    rip = context->getRip();
	    uint32_t destifeq = (static_cast<uint32_t>(ptr[rip+3] ^ context->getKey()) |
	                      (static_cast<uint32_t>(ptr[rip+2] ^ context->getKey()) << 8) |
	                      (static_cast<uint32_t>(ptr[rip+1] ^ context->getKey()) << 16) |
	                      (static_cast<uint32_t>(ptr[rip+0] ^ context->getKey()) << 24));

	    
	    if (context->getRegister(15) != 1) {
	        // Setup for next instruction execution
	        context->setRip(0);
	        context->setInstructionCpt(destifeq);
	        context->setLip(context->shuffling_map.find(context->getInstructionCpt())->second.first);
	        context->setKey(context->shuffling_map.find(context->getInstructionCpt())->second.second);
	    } else {
	        // Setup for next instruction execution
	        context->setRip(0);
	        context->incrementInstructionCpt();
	        context->setLip(context->shuffling_map.find(context->getInstructionCpt())->second.first);
	        context->setKey(context->shuffling_map.find(context->getInstructionCpt())->second.second);
	    }
	    
    	Dispatcher::registerOpcode(VM::OPCODE::JG, std::make_unique<JGHandler>());
	}


void JLEHandler::execute(VM* context) {
	    //printf("JLE\n");
	    const std::vector<uint8_t>* row = &(context->bytearrayPtr->at(context->getLip()));
	    const uint8_t* ptr = row->data();
	    uint64_t rip = context->getRip();
	    context->setRip(context->getRip()+1);
	    rip = context->getRip();
	    uint32_t destifeq = (static_cast<uint32_t>(ptr[rip+3] ^ context->getKey()) |
	                      (static_cast<uint32_t>(ptr[rip+2] ^ context->getKey()) << 8) |
	                      (static_cast<uint32_t>(ptr[rip+1] ^ context->getKey()) << 16) |
	                      (static_cast<uint32_t>(ptr[rip+0] ^ context->getKey()) << 24));
	    
	    
	    if (context->getRegister(15) != 10) {
	        // Setup for next instruction execution
	        context->setRip(0);
	        context->setInstructionCpt(destifeq);
	        context->setLip(context->shuffling_map.find(context->getInstructionCpt())->second.first);
	        context->setKey(context->shuffling_map.find(context->getInstructionCpt())->second.second);
	    } else {
	        // Setup for next instruction execution
	        context->setRip(0);
	        context->incrementInstructionCpt();
	        context->setLip(context->shuffling_map.find(context->getInstructionCpt())->second.first);
	        context->setKey(context->shuffling_map.find(context->getInstructionCpt())->second.second);
	    }
	    
    	Dispatcher::registerOpcode(VM::OPCODE::CMPS, std::make_unique<CMPSHandler>());
	}


void JZHandler::execute(VM* context) {
	    //printf("JZ\n");
	    const std::vector<uint8_t>* row = &(context->bytearrayPtr->at(context->getLip()));
	    const uint8_t* ptr = row->data();
	    uint64_t rip = context->getRip();
	    context->setRip(context->getRip()+1);
	    rip = context->getRip();
	    uint32_t destifeq = (static_cast<uint32_t>(ptr[rip+3] ^ context->getKey()) |
	                      (static_cast<uint32_t>(ptr[rip+2] ^ context->getKey()) << 8) |
	                      (static_cast<uint32_t>(ptr[rip+1] ^ context->getKey()) << 16) |
	                      (static_cast<uint32_t>(ptr[rip+0] ^ context->getKey()) << 24));

	    
	    if (context->getRegister(15) == 1) {
	        // Setup for next instruction execution
	        context->setRip(0);
	        context->setInstructionCpt(destifeq);
	        context->setLip(context->shuffling_map.find(context->getInstructionCpt())->second.first);
	        context->setKey(context->shuffling_map.find(context->getInstructionCpt())->second.second);
	    } else {
	        // Setup for next instruction execution
	        context->setRip(0);
	        context->incrementInstructionCpt();
	        context->setLip(context->shuffling_map.find(context->getInstructionCpt())->second.first);
	        context->setKey(context->shuffling_map.find(context->getInstructionCpt())->second.second);
	    }
	    
    	Dispatcher::registerOpcode(VM::OPCODE::LDRS, std::make_unique<handleLoadMemoryValueToReg32S>());
	}


void JGHandler::execute(VM* context) {
	    //printf("JG\n");
	    const std::vector<uint8_t>* row = &(context->bytearrayPtr->at(context->getLip()));
	    const uint8_t* ptr = row->data();
	    uint64_t rip = context->getRip();
	    context->setRip(context->getRip()+1);
	    rip = context->getRip();
	    uint32_t destifeq = (static_cast<uint32_t>(ptr[rip+3] ^ context->getKey()) |
	                      (static_cast<uint32_t>(ptr[rip+2] ^ context->getKey()) << 8) |
	                      (static_cast<uint32_t>(ptr[rip+1] ^ context->getKey()) << 16) |
	                      (static_cast<uint32_t>(ptr[rip+0] ^ context->getKey()) << 24));
	 
	    
	    if (context->getRegister(15) == 10) {
	        // Setup for next instruction execution
	        context->setRip(0);
	        context->setInstructionCpt(destifeq);
	        context->setLip(context->shuffling_map.find(context->getInstructionCpt())->second.first);
	        context->setKey(context->shuffling_map.find(context->getInstructionCpt())->second.second);
	    } else {
	        // Setup for next instruction execution
	        context->setRip(0);
	        context->incrementInstructionCpt();
	        context->setLip(context->shuffling_map.find(context->getInstructionCpt())->second.first);
	        context->setKey(context->shuffling_map.find(context->getInstructionCpt())->second.second);
	    }
	    
		Dispatcher::registerOpcode(VM::OPCODE::LOT2, std::make_unique<LOT2Handler>());
	}


void JMPHandler::execute(VM* context) {
		//printf("JMP\n");
	    const std::vector<uint8_t>* row = &(context->bytearrayPtr->at(context->getLip()));
	    const uint8_t* ptr = row->data();
	    uint64_t rip = context->getRip();
	    context->setRip(context->getRip()+1);
	    rip = context->getRip();
	    uint32_t dest = (static_cast<uint32_t>(ptr[rip+3] ^ context->getKey()) |
	                      (static_cast<uint32_t>(ptr[rip+2] ^ context->getKey()) << 8) |
	                      (static_cast<uint32_t>(ptr[rip+1] ^ context->getKey()) << 16) |
	                      (static_cast<uint32_t>(ptr[rip+0] ^ context->getKey()) << 24));

	    // Setup for next instruction execution
	    context->setRip(0);
	    context->setInstructionCpt(dest);
	    context->setLip(context->shuffling_map.find(context->getInstructionCpt())->second.first);
	    context->setKey(context->shuffling_map.find(context->getInstructionCpt())->second.second);
		
		Dispatcher::registerOpcode(VM::OPCODE::ADD, std::make_unique<ADDDispatcher>());
		Dispatcher::registerOpcode(VM::OPCODE::ADDD, std::make_unique<ADDDupDispatcher>());
		Dispatcher::registerOpcode(VM::OPCODE::ADP, std::make_unique<handleAntiDebugProc>());
	}


void LOT2Handler::execute(VM* context) {
		//printf("LOT2\n");
	    uint64_t srcValue;

	    // MOV [0], [4]
	    srcValue = context->getRegister(4);
	    context->setRegister(0, srcValue);

	    // MOV [3], [0]
	    srcValue = context->getRegister(0);
	    context->setRegister(3, srcValue);

	    // MOV [0], [13]
	    srcValue = context->getRegister(13);
	    context->setRegister(0, srcValue);

	    // ADD [0], [3]
	    srcValue = context->getRegister(0) + context->getRegister(3);
	    context->setRegister(0, srcValue);

	    // MOV [2], [0]
	    srcValue = context->getRegister(0);
	    uint8_t input_byte = *(uint8_t*)srcValue;
	    context->setRegister(2, input_byte);

	    // MOV [0], [5]
	    srcValue = context->getRegister(5);
	    context->setRegister(0, srcValue);

	    // MOV [3], [0]
	    srcValue = context->getRegister(0);
	    context->setRegister(3, srcValue);

	    // MOV [0], [3]
	    srcValue = context->getRegister(3);
	    context->setRegister(0, srcValue);

	    // SHL [0], 0x3
	    srcValue = context->getRegister(0) << 0x3;
	    context->setRegister(0, srcValue);

	    // ADD [0], [3]
	    srcValue = context->getRegister(0) + context->getRegister(3);
	    context->setRegister(0, srcValue);

	    // SHL [0], 0x2
	    srcValue = context->getRegister(0) << 0x2;
	    context->setRegister(0, srcValue);

	    // MOV [3], [0]
	    srcValue = context->getRegister(0);
	    context->setRegister(3, srcValue);

	    // MOV [0], [14]
	    srcValue = context->getRegister(14);
	    context->setRegister(0, srcValue);

	    // ADD [3], [0]
	    srcValue = context->getRegister(3) + context->getRegister(0);
	    context->setRegister(3, srcValue);

	    // SUB [2], 0x30
	    srcValue = context->getRegister(2) - 0x30;
	    context->setRegister(2, srcValue);

	    // MOV [0], [6]
	    srcValue = context->getRegister(6);
	    context->setRegister(0, srcValue);
	    
	    // MUL [0], 0x4
	    srcValue = context->getRegister(0) * 0x4;
	    context->setRegister(0, srcValue);
	    
	    // ADD [3], [0]
	    srcValue = context->getRegister(3) + context->getRegister(0);
	    context->setRegister(3, srcValue);

	    // STR [3], [2]
	    uint64_t address = context->getRegister(3);
	    uint64_t value = context->getRegister(2);
	    int intValue = static_cast<int>(value);
	    *(uint8_t*)address = intValue;
	    

	    // ADD [4], 0x1
	    srcValue = context->getRegister(4) + 0x1;
	    context->setRegister(4, srcValue);

	    // Setup for next instruction execution
	    context->setRip(0);
	    context->incrementInstructionCpt();
	    context->setLip(context->shuffling_map.find(context->getInstructionCpt())->second.first);
	    context->setKey(context->shuffling_map.find(context->getInstructionCpt())->second.second);
		
		Dispatcher::registerOpcode(VM::OPCODE::CMPSC, std::make_unique<CMPSCHandler>());
	}


void LOTHandler::execute(VM* context) {
		//printf("LOT\n");
	    uint64_t srcValue;

	    // MOV [0], [5]
	    srcValue = context->getRegister(5);
	    context->setRegister(0, srcValue);

	    // MOV [3], [0]
	    srcValue = context->getRegister(0);
	    context->setRegister(3, srcValue);

	    // MOV [0], [3]
	    srcValue = context->getRegister(3);
	    context->setRegister(0, srcValue);

	    // SHL [0], 0x3
	    srcValue = context->getRegister(0) << 0x3;
	    context->setRegister(0, srcValue);

	    // ADD [0], [3]
	    srcValue = context->getRegister(0) + context->getRegister(3);
	    context->setRegister(0, srcValue);

	    // SHL [0], 0x2
	    srcValue = context->getRegister(0) << 0x2;
	    context->setRegister(0, srcValue);

	    // MOV [3], [0]
	    srcValue = context->getRegister(0);
	    context->setRegister(3, srcValue);

	    // MOV [0], [14]
	    srcValue = context->getRegister(14);
	    context->setRegister(0, srcValue);

	    // ADD [3], [0]
	    srcValue = context->getRegister(3) + context->getRegister(0);
	    context->setRegister(3, srcValue);

	    // MOV [0], [6]
	    srcValue = context->getRegister(6);
	    context->setRegister(0, srcValue);

	    // MUL [0], 0x4
	    srcValue = context->getRegister(0) * 0x4;
	    context->setRegister(0, srcValue);

	    // ADD [3], [0]
	    srcValue = context->getRegister(3) + context->getRegister(0);
	    context->setRegister(3, srcValue);

	    // LDR [0], [3]
	    srcValue = context->getRegister(3);
	    int value = *(int*)srcValue;
	    context->setRegister(0, value);

	    // Setup for next instruction execution
	    context->setRip(0);
	    context->incrementInstructionCpt();
	    context->setLip(context->shuffling_map.find(context->getInstructionCpt())->second.first);
	    context->setKey(context->shuffling_map.find(context->getInstructionCpt())->second.second);
		
		Dispatcher::registerOpcode(VM::OPCODE::CMP, std::make_unique<CMPHandler>());
	}


void CMPSCHandler::execute(VM* context) {
		//printf("CMPSC\n");
	    const std::vector<uint8_t>* row = &(context->bytearrayPtr->at(context->getLip()));
	    const uint8_t* ptr = row->data();
	    uint64_t rip = context->getRip();
	    context->setRip(context->getRip()+1);
	    rip = context->getRip();
	    uint8_t dest = ptr[rip] ^ context->getKey();
	    uint32_t immediate = (static_cast<uint32_t>(ptr[rip+4] ^ context->getKey()) |
	                      (static_cast<uint32_t>(ptr[rip+3] ^ context->getKey()) << 8) |
	                      (static_cast<uint32_t>(ptr[rip+2] ^ context->getKey()) << 16) |
	                      (static_cast<uint32_t>(ptr[rip+1] ^ context->getKey()) << 24));

	    if (context->getRegister(dest) == immediate) {
	        context->setRegister(15, 1); // Set the first bit (bit 0)
	    } else if(context->getRegister(dest) < immediate) {
	        context->setRegister(15, 6);
	    } else {
	        context->setRegister(15, 10);
	    }

	    // Setup for next instruction execution
	    context->setRip(0);
	    context->incrementInstructionCpt();
	    context->setLip(context->shuffling_map.find(context->getInstructionCpt())->second.first);
	    context->setKey(context->shuffling_map.find(context->getInstructionCpt())->second.second);

	    Dispatcher::registerOpcode(VM::OPCODE::ADD, std::make_unique<ADDDispatcher>());
		Dispatcher::registerOpcode(VM::OPCODE::ADDD, std::make_unique<ADDDupDispatcher>());
		
	}


void CMPSHandler::execute(VM* context) {
		//printf("CMPS\n");
	    const std::vector<uint8_t>* row = &(context->bytearrayPtr->at(context->getLip()));
	    const uint8_t* ptr = row->data();
	    uint64_t rip = context->getRip();
	    context->setRip(context->getRip()+1);
	    rip = context->getRip();
	    uint8_t dest = ptr[rip] ^ context->getKey();
	    uint8_t src = ptr[rip+1] ^ context->getKey();

	    if (context->getRegister(dest) == context->getRegister(src)) {
	        context->setRegister(15, 1); // Set the first bit (bit 0)
	    } else if(context->getRegister(dest) < context->getRegister(src)) {
	        context->setRegister(15, 6);
	    } else {
	        context->setRegister(15, 10);
	    }

	    // Setup for next instruction execution
	    context->setRip(0);
	    context->incrementInstructionCpt();
	    context->setLip(context->shuffling_map.find(context->getInstructionCpt())->second.first);
	    context->setKey(context->shuffling_map.find(context->getInstructionCpt())->second.second);
		
		Dispatcher::registerOpcode(VM::OPCODE::CMPRR, std::make_unique<CMPRRHandler>());
	}


void CMPRRHandler::execute(VM* context) {
		//printf("CMPR\n");
	    const std::vector<uint8_t>* row = &(context->bytearrayPtr->at(context->getLip()));
	    const uint8_t* ptr = row->data();
	    uint64_t rip = context->getRip();
	    context->setRip(context->getRip()+1);
	    rip = context->getRip();
	    uint8_t dest = ptr[rip] ^ context->getKey();
	    uint8_t src = ptr[rip+1] ^ context->getKey();

	    if (context->getRegister(dest) == context->getRegister(src)) {
	        context->setRegister(15, 1); // Set the first bit (bit 0)
	    } else if(context->getRegister(dest) < context->getRegister(src)) {
	        context->setRegister(15, 6);
	    } else {
	        context->setRegister(15, 10);
	    }

	    // Setup for next instruction execution
	    context->setRip(0);
	    context->incrementInstructionCpt();
	    context->setLip(context->shuffling_map.find(context->getInstructionCpt())->second.first);
	    context->setKey(context->shuffling_map.find(context->getInstructionCpt())->second.second);
		
		Dispatcher::registerOpcode(VM::OPCODE::IMUL, std::make_unique<IMULHandler>());
	}


void CMPHandler::execute(VM* context) {
		//printf("CMPC\n");
	    const std::vector<uint8_t>* row = &(context->bytearrayPtr->at(context->getLip()));
	    const uint8_t* ptr = row->data();
	    uint64_t rip = context->getRip();
	    context->setRip(context->getRip()+1);
	    rip = context->getRip();
	    uint8_t dest = ptr[rip] ^ context->getKey();
	    uint32_t immediate = (static_cast<uint32_t>(ptr[rip+4] ^ context->getKey()) |
	                      (static_cast<uint32_t>(ptr[rip+3] ^ context->getKey()) << 8) |
	                      (static_cast<uint32_t>(ptr[rip+2] ^ context->getKey()) << 16) |
	                      (static_cast<uint32_t>(ptr[rip+1] ^ context->getKey()) << 24));

	    if (context->getRegister(dest) == immediate) {
	        context->setRegister(15, 1); // Set the first bit (bit 0)
	    } else if(context->getRegister(dest) < immediate) {
	        context->setRegister(15, 6);
	    } else {
	        context->setRegister(15, 10);
	    }

	    // Setup for next instruction execution
	    context->setRip(0);
	    context->incrementInstructionCpt();
	    context->setLip(context->shuffling_map.find(context->getInstructionCpt())->second.first);
	    context->setKey(context->shuffling_map.find(context->getInstructionCpt())->second.second);
		
		Dispatcher::registerOpcode(VM::OPCODE::JNZ, std::make_unique<JNZHandler>());
	}


void IMULHandler::execute(VM* context) {
		//printf("IMUL\n");
	    const std::vector<uint8_t>* row = &(context->bytearrayPtr->at(context->getLip()));
	    const uint8_t* ptr = row->data();
	    uint64_t rip = context->getRip();
	    //////printf("Opcode %x\n", ptr[rip]);
	    context->setRip(context->getRip()+1);
	    rip = context->getRip();
	    uint8_t dest = ptr[rip] ^ context->getKey();
	    uint32_t immediate = (static_cast<uint32_t>(ptr[rip+4] ^ context->getKey()) |
	                      (static_cast<uint32_t>(ptr[rip+3] ^ context->getKey()) << 8) |
	                      (static_cast<uint32_t>(ptr[rip+2] ^ context->getKey()) << 16) |
	                      (static_cast<uint32_t>(ptr[rip+1] ^ context->getKey()) << 24));
	    uint64_t result = context->getRegister(dest) * immediate;

	    context->setRegister(dest, result);

	    // Setup for next instruction execution
	    context->setRip(0);
	    context->incrementInstructionCpt();
	    context->setLip(context->shuffling_map.find(context->getInstructionCpt())->second.first);
	    context->setKey(context->shuffling_map.find(context->getInstructionCpt())->second.second);
		
		Dispatcher::registerOpcode(VM::OPCODE::SHR, std::make_unique<SHRHandler>());
	}


void SARDupHandler::execute(VM* context) {
		//printf("SAR\n");
	    const std::vector<uint8_t>* row = &(context->bytearrayPtr->at(context->getLip()));
	    const uint8_t* ptr = row->data();
	    uint64_t rip = context->getRip(); // rip = opcode
	    //////printf("Opcode %x\n", ptr[rip]);
	    context->setRip(context->getRip()+1); // operand dst
	    rip = context->getRip(); // rip = operand dst
	    uint8_t dest = ptr[rip] ^ context->getKey();
	    uint8_t src = ptr[rip + 1] ^ context->getKey();
	    uint64_t result = context->getRegister(dest) >> src;

	    context->setRegister(dest, result);

	    // Setup for next instruction execution
	    context->setRip(0);
	    context->incrementInstructionCpt();
	    context->setLip(context->shuffling_map.find(context->getInstructionCpt())->second.first);
	    context->setKey(context->shuffling_map.find(context->getInstructionCpt())->second.second);
		
		Dispatcher::registerOpcode(VM::OPCODE::SUB, std::make_unique<SUBDispatcher>());
	}


void SARHandler::execute(VM* context) {
		//printf("SAR\n");
	    const std::vector<uint8_t>* row = &(context->bytearrayPtr->at(context->getLip()));
	    const uint8_t* ptr = row->data();
	    uint64_t rip = context->getRip(); // rip = opcode
	    //////printf("Opcode %x\n", ptr[rip]);
	    context->setRip(context->getRip()+1); // operand dst
	    rip = context->getRip(); // rip = operand dst
	    uint8_t dest = ptr[rip] ^ context->getKey();
	    uint8_t src = ptr[rip + 1] ^ context->getKey();
	    uint64_t result = context->getRegister(dest) >> src;

	    context->setRegister(dest, result);

	    // Setup for next instruction execution
	    context->setRip(0);
	    context->incrementInstructionCpt();
	    context->setLip(context->shuffling_map.find(context->getInstructionCpt())->second.first);
	    context->setKey(context->shuffling_map.find(context->getInstructionCpt())->second.second);
		
		Dispatcher::registerOpcode(VM::OPCODE::SUB, std::make_unique<SUBDispatcher>());
	}


void SHRHandler::execute(VM* context) {
		//printf("SHR\n");
	    const std::vector<uint8_t>* row = &(context->bytearrayPtr->at(context->getLip()));
	    const uint8_t* ptr = row->data();
	    uint64_t rip = context->getRip(); // rip = opcode
	    //////printf("Opcode %x\n", ptr[rip]);
	    context->setRip(context->getRip()+1); // operand dst
	    rip = context->getRip(); // rip = operand dst
	    uint8_t dest = ptr[rip] ^ context->getKey();
	    uint8_t src = ptr[rip + 1] ^ context->getKey();
	    uint64_t result = static_cast<uint64_t>(context->getRegister(dest)) >> src;

	    context->setRegister(dest, result);

	    // Setup for next instruction execution
	    context->setRip(0);
	    context->incrementInstructionCpt();
	    context->setLip(context->shuffling_map.find(context->getInstructionCpt())->second.first);
	    context->setKey(context->shuffling_map.find(context->getInstructionCpt())->second.second);
		
		Dispatcher::registerOpcode(VM::OPCODE::SAR, std::make_unique<SARHandler>());
		Dispatcher::registerOpcode(VM::OPCODE::SARD, std::make_unique<SARDupHandler>());
	}


void CALLOutHandler::execute(VM* context) {
		//printf("CALLO\n");
	    const std::vector<uint8_t>* row = &(context->bytearrayPtr->at(context->getLip()));
	    const uint8_t* ptr = row->data();
	    uint64_t rip = context->getRip();

	    context->return_rax();
	    context->restore_registers();
	    // Setup for next instruction execution
	    context->setRip(0);
	    context->incrementInstructionCpt();
	    context->setLip(context->shuffling_map.find(context->getInstructionCpt())->second.first);
	    context->setKey(context->shuffling_map.find(context->getInstructionCpt())->second.second);
		
		Dispatcher::registerOpcode(VM::OPCODE::XOR, std::make_unique<XORDispatcher>());
	}


void CALLInHandler::execute(VM* context) {
		//printf("CALLI\n");
	    const std::vector<uint8_t>* row = &(context->bytearrayPtr->at(context->getLip()));
	    const uint8_t* ptr = row->data();
	    uint64_t rip = context->getRip();

	    context->backup_registers();
	    // Setup for next instruction execution
	    context->setRip(0);
	    context->incrementInstructionCpt();
	    context->setLip(context->shuffling_map.find(context->getInstructionCpt())->second.first);
	    context->setKey(context->shuffling_map.find(context->getInstructionCpt())->second.second);
		
		Dispatcher::registerOpcode(VM::OPCODE::JLE, std::make_unique<JLEHandler>());
	}


void SHLDupHandler::execute(VM* context) {
		//printf("SHL\n");
	    const std::vector<uint8_t>* row = &(context->bytearrayPtr->at(context->getLip()));
	    const uint8_t* ptr = row->data();
	    uint64_t rip = context->getRip();
	    context->setRip(context->getRip()+1);
	    rip = context->getRip();
	    uint8_t dest = ptr[rip] ^ context->getKey();
	    uint8_t src = ptr[rip + 1] ^ context->getKey();
	    uint64_t result = context->getRegister(dest) << src;

	    context->setRegister(dest, result);

	    // Setup for next instruction execution
	    context->setRip(0);
	    context->incrementInstructionCpt();
	    context->setLip(context->shuffling_map.find(context->getInstructionCpt())->second.first);
	    context->setKey(context->shuffling_map.find(context->getInstructionCpt())->second.second);
		
		//Dispatcher::registerOpcode(opcode, std::make_unique<SubHandler>());
	}


void SHLHandler::execute(VM* context) {
		//printf("SHL\n");
	    const std::vector<uint8_t>* row = &(context->bytearrayPtr->at(context->getLip()));
	    const uint8_t* ptr = row->data();
	    uint64_t rip = context->getRip();
	    context->setRip(context->getRip()+1);
	    rip = context->getRip();
	    uint8_t dest = ptr[rip] ^ context->getKey();
	    uint8_t src = ptr[rip + 1] ^ context->getKey();
	    uint64_t result = context->getRegister(dest) << src;

	    context->setRegister(dest, result);

	    // Setup for next instruction execution
	    context->setRip(0);
	    context->incrementInstructionCpt();
	    context->setLip(context->shuffling_map.find(context->getInstructionCpt())->second.first);
	    context->setKey(context->shuffling_map.find(context->getInstructionCpt())->second.second);
		
		//Dispatcher::registerOpcode(opcode, std::make_unique<SubHandler>());
	}


void XORDispatcher::execute(VM* context) {
	std::unique_ptr<XORHandler> xorHandlerInstance = std::make_unique<XORHandler>();
	const std::vector<uint8_t>* row = &(context->bytearrayPtr->at(context->getLip()));
    const uint8_t* ptr = row->data();
    uint64_t rip = context->getRip();
    context->setRip(rip+1);
    switch(ptr[rip+1] ^ context->getKey()){
        case VM::OPCODE::XOR_RC:
            xorHandlerInstance->execute(context);
            break;
    }
}


void MOVDupDispatcher::execute(VM* context) {
	std::unique_ptr<MOVRHandler> movrHandlerInstance = std::make_unique<MOVRHandler>();
	std::unique_ptr<MOVCHandler> movcHandlerInstance = std::make_unique<MOVCHandler>();
	const std::vector<uint8_t>* row = &(context->bytearrayPtr->at(context->getLip()));
	const uint8_t* ptr = row->data();
	uint64_t rip = context->getRip();
	context->setRip(rip+1);
	switch(ptr[rip+1] ^ context->getKey()){
	        case VM::OPCODE::MOV_RR:
	            movrHandlerInstance->execute(context);
	            break;
	        case VM::OPCODE::MOV_RC:
	            movcHandlerInstance->execute(context);
	            break;
	}
}


void MOVDispatcher::execute(VM* context){
	std::unique_ptr<MOVRHandler> movrHandlerInstance = std::make_unique<MOVRHandler>();
	std::unique_ptr<MOVCHandler> movcHandlerInstance = std::make_unique<MOVCHandler>();
	const std::vector<uint8_t>* row = &(context->bytearrayPtr->at(context->getLip()));
	const uint8_t* ptr = row->data();
	uint64_t rip = context->getRip();
	context->setRip(rip+1);
	switch(ptr[rip+1] ^ context->getKey()){
	        case VM::OPCODE::MOV_RR:
	            movrHandlerInstance->execute(context);
	            break;
	        case VM::OPCODE::MOV_RC:
	            movcHandlerInstance->execute(context);
	            break;
	}
}


void MULDispatcher::execute(VM* context) {
	std::unique_ptr<MULHandler> mulHandlerInstance = std::make_unique<MULHandler>();
	const std::vector<uint8_t>* row = &(context->bytearrayPtr->at(context->getLip()));
    const uint8_t* ptr = row->data();
    uint64_t rip = context->getRip();
    context->setRip(rip+1);
    switch(ptr[rip+1] ^ context->getKey()){
        case VM::OPCODE::MUL_RC:
            mulHandlerInstance->execute(context);
            break;
    }
}


void SUBDispatcher::execute(VM* context) {
	std::unique_ptr<SUBRHandler> subrHandlerInstance = std::make_unique<SUBRHandler>();
	const std::vector<uint8_t>* row = &(context->bytearrayPtr->at(context->getLip()));
    const uint8_t* ptr = row->data();
    uint64_t rip = context->getRip();

    context->setRip(rip+1);
    switch(ptr[rip+1] ^ context->getKey()){
        case VM::OPCODE::SUB_RR:
            subrHandlerInstance->execute(context);
            break;
    }
}


void ADDDupDispatcher::execute(VM* context) {
	std::unique_ptr<ADDRHandler> addrHandlerInstance = std::make_unique<ADDRHandler>();
	std::unique_ptr<ADDCHandler> addcHandlerInstance = std::make_unique<ADDCHandler>();
	std::unique_ptr<ADDSHandler> addsHandlerInstance = std::make_unique<ADDSHandler>();
	const std::vector<uint8_t>* row = &(context->bytearrayPtr->at(context->getLip()));
    const uint8_t* ptr = row->data();
    uint64_t rip = context->getRip();
    context->setRip(rip+1);
    switch(ptr[rip+1] ^ context->getKey()){
        case VM::OPCODE::ADD_RR:
            addrHandlerInstance->execute(context);
            break;
        case VM::OPCODE::ADD_RC:
            addcHandlerInstance->execute(context);
            break;
        case VM::OPCODE::ADD_S:
            addsHandlerInstance->execute(context);
            break;
    }
}


void ADDDispatcher::execute(VM* context) {
	std::unique_ptr<ADDRHandler> addrHandlerInstance = std::make_unique<ADDRHandler>();
	std::unique_ptr<ADDCHandler> addcHandlerInstance = std::make_unique<ADDCHandler>();
	std::unique_ptr<ADDSHandler> addsHandlerInstance = std::make_unique<ADDSHandler>();
	const std::vector<uint8_t>* row = &(context->bytearrayPtr->at(context->getLip()));
    const uint8_t* ptr = row->data();
    uint64_t rip = context->getRip();
    context->setRip(rip+1);
    switch(ptr[rip+1] ^ context->getKey()){
        case VM::OPCODE::ADD_RR:
            addrHandlerInstance->execute(context);
            break;
        case VM::OPCODE::ADD_RC:
            addcHandlerInstance->execute(context);
            break;
        case VM::OPCODE::ADD_S:
            addsHandlerInstance->execute(context);
            break;
    }
}


void XORHandler::execute(VM* context) {
		//printf("XOR\n");
	    const std::vector<uint8_t>* row = &(context->bytearrayPtr->at(context->getLip()));
	    const uint8_t* ptr = row->data();
	    uint64_t rip = context->getRip();
	    context->setRip(rip+1);
	    rip = context->getRip();
	    uint8_t dest = ptr[rip] ^ context->getKey();
	    uint8_t src = ptr[rip + 1] ^ context->getKey();
	    uint64_t result = context->getRegister(dest) ^ src;

	    context->setRegister(dest, result);

	    // Setup for next instruction execution
	    context->setRip(0);
	    context->incrementInstructionCpt();
	    context->setLip(context->shuffling_map.find(context->getInstructionCpt())->second.first);
	    context->setKey(context->shuffling_map.find(context->getInstructionCpt())->second.second);
		
		Dispatcher::registerOpcode(VM::OPCODE::STRR, std::make_unique<StoreRegToMemoryHandler>()); //StoreRegToMemoryHandler
	}


void MULHandler::execute(VM* context) {
		//printf("MUL\n");
	    const std::vector<uint8_t>* row = &(context->bytearrayPtr->at(context->getLip()));
	    const uint8_t* ptr = row->data();
	    uint64_t rip = context->getRip();
	    context->setRip(rip+1);
	    rip = context->getRip();
	    uint8_t dest = ptr[rip] ^ context->getKey();
	    uint8_t src = ptr[rip + 1] ^ context->getKey();
	    uint64_t result = context->getRegister(dest) * src;

	    context->setRegister(dest, result);

	    // Setup for next instruction execution
	    context->setRip(0);
	    context->incrementInstructionCpt();
	    context->setLip(context->shuffling_map.find(context->getInstructionCpt())->second.first);
	    context->setKey(context->shuffling_map.find(context->getInstructionCpt())->second.second);
		
		Dispatcher::registerOpcode(VM::OPCODE::LDR, std::make_unique<handleLoadMemoryValueToReg32Dup>());
		Dispatcher::registerOpcode(VM::OPCODE::LDRD, std::make_unique<handleLoadMemoryValueToReg32>());
	}


void MOVCHandler::execute(VM* context) {
		//printf("MOVC\n");
	    const std::vector<uint8_t>* row = &(context->bytearrayPtr->at(context->getLip()));
	    const uint8_t* ptr = row->data();
	    uint64_t rip = context->getRip();
	    context->setRip(rip+1);
	    rip = context->getRip();
	    uint8_t dest = ptr[rip] ^ context->getKey();
	    uint8_t src = ptr[rip + 1] ^ context->getKey();
	    uint64_t src64 = static_cast<uint64_t>(src);

	    context->setRegister(dest, src64);

	    // Setup for next instruction execution
	    context->setRip(0);
	    context->incrementInstructionCpt();
	    context->setLip(context->shuffling_map.find(context->getInstructionCpt())->second.first);
	    context->setKey(context->shuffling_map.find(context->getInstructionCpt())->second.second);
		
		Dispatcher::registerOpcode(VM::OPCODE::LOT, std::make_unique<LOTHandler>());
		//printf("LOT registered %x\n", VM::OPCODE::LOT);
	}


void MOVRHandler::execute(VM* context) {
		//printf("MOVR\n");
	    const std::vector<uint8_t>* row = &(context->bytearrayPtr->at(context->getLip()));
	    const uint8_t* ptr = row->data();
	    uint64_t rip = context->getRip();
	    context->setRip(rip+1);
	    rip = context->getRip();
	    uint8_t dest = ptr[rip] ^ context->getKey();
	    uint8_t src = ptr[rip + 1] ^ context->getKey();
	    uint64_t srcValue = context->getRegister(src);

	    context->setRegister(dest, srcValue); 

	    // Setup for next instruction execution
	    context->setRip(0);
	    context->incrementInstructionCpt();
	    context->setLip(context->shuffling_map.find(context->getInstructionCpt())->second.first);
	    context->setKey(context->shuffling_map.find(context->getInstructionCpt())->second.second);
		
		Dispatcher::registerOpcode(VM::OPCODE::SHL, std::make_unique<SHLHandler>());
		Dispatcher::registerOpcode(VM::OPCODE::SHLD, std::make_unique<SHLDupHandler>());
	}


void SUBRHandler::execute(VM* context) {
		//printf("SUBR\n");
	    const std::vector<uint8_t>* row = &(context->bytearrayPtr->at(context->getLip()));
	    const uint8_t* ptr = row->data();
	    uint64_t rip = context->getRip();
	    context->setRip(rip+1);
	    rip = context->getRip();
	    uint8_t dest = ptr[rip] ^ context->getKey();
	    uint8_t src = ptr[rip+1] ^ context->getKey();
	    uint64_t result = context->getRegister(dest) - context->getRegister(src);

	    context->setRegister(dest, result);

	    // Setup for next instruction execution
	    context->setRip(0);
	    context->incrementInstructionCpt();
	    context->setLip(context->shuffling_map.find(context->getInstructionCpt())->second.first);
	    context->setKey(context->shuffling_map.find(context->getInstructionCpt())->second.second);
		
		Dispatcher::registerOpcode(VM::OPCODE::NOPP, std::make_unique<NOPDupHandler>());
	}


void ADDSHandler::execute(VM* context) {
		//printf("ADDS\n");
	    const std::vector<uint8_t>* row = &(context->bytearrayPtr->at(context->getLip()));
	    const uint8_t* ptr = row->data();
	    uint64_t rip = context->getRip();
	    context->setRip(rip+1);
	    rip = context->getRip();
	    uint8_t dest = ptr[rip] ^ context->getKey();
	    uint8_t src = ptr[rip + 1] ^ context->getKey();
	    uint64_t result = context->getRegister(dest) + src;

	    context->setRegister(dest, result);

	    // Setup for next instruction execution
	    context->setRip(0);
	    context->incrementInstructionCpt();
	    context->setLip(context->shuffling_map.find(context->getInstructionCpt())->second.first);
	    context->setKey(context->shuffling_map.find(context->getInstructionCpt())->second.second);
		
		//Dispatcher::registerOpcode(opcode, std::make_unique<SubHandler>());
	}


void ADDCHandler::execute(VM* context) {
		//printf("ADDC\n");
	    const std::vector<uint8_t>* row = &(context->bytearrayPtr->at(context->getLip()));
	    const uint8_t* ptr = row->data();
	    uint64_t rip = context->getRip();
	    context->setRip(rip+1);
	    rip = context->getRip();
	    uint8_t dest = ptr[rip] ^ context->getKey();
	    uint8_t src = ptr[rip+1] ^ context->getKey();
	    uint64_t result = context->getRegister(dest) + src;

	    context->setRegister(dest, result);

	    // Setup for next instruction execution
	    context->setRip(0);
	    context->incrementInstructionCpt();
	    context->setLip(context->shuffling_map.find(context->getInstructionCpt())->second.first);
	    context->setKey(context->shuffling_map.find(context->getInstructionCpt())->second.second);
		
		Dispatcher::registerOpcode(VM::OPCODE::JMP, std::make_unique<JMPHandler>());
	}


void ADDRHandler::execute(VM* context) {
		//printf("ADDR\n");
	    const std::vector<uint8_t>* row = &(context->bytearrayPtr->at(context->getLip()));
	    const uint8_t* ptr = row->data();
	    uint64_t rip = context->getRip();
	    context->setRip(rip+1);
	    rip = context->getRip();
	    uint8_t dest = ptr[rip] ^ context->getKey();
	    uint8_t src = ptr[rip+1] ^ context->getKey();
	    uint64_t result = context->getRegister(dest) + context->getRegister(src);

	    context->setRegister(dest, result);

	    // Setup for next instruction execution
	    context->setRip(0);
	    context->incrementInstructionCpt();
	    context->setLip(context->shuffling_map.find(context->getInstructionCpt())->second.first);
	    context->setKey(context->shuffling_map.find(context->getInstructionCpt())->second.second);
		
		Dispatcher::registerOpcode(VM::OPCODE::NOP, std::make_unique<NOPHandler>());
	}


void StoreRegToMemoryHandler::execute(VM* context) {
		//printf("STRR\n");
	    const std::vector<uint8_t>* row = &(context->bytearrayPtr->at(context->getLip()));
	    const uint8_t* ptr = row->data();
	    uint64_t rip = context->getRip();
	    context->setRip(context->getRip()+1);
	    rip = context->getRip();
	    uint8_t dest = ptr[rip] ^ context->getKey();
	    uint8_t src = ptr[rip+1] ^ context->getKey();
	    uint64_t address = context->getRegister(dest);
	    uint32_t value = context->getRegister(src);
	    *(int*)address = value;

	    // Setup for next instruction execution
	    context->setRip(0);
	    context->incrementInstructionCpt();
	    context->setLip(context->shuffling_map.find(context->getInstructionCpt())->second.first);
	    context->setKey(context->shuffling_map.find(context->getInstructionCpt())->second.second);
		
		//Dispatcher::registerOpcode(VM::OPCODE::ADD_S, std::make_unique<ADDSHandler>());
	}


void StoreValueToMemory::execute(VM* context) {
		//printf("STRC\n");
	    const std::vector<uint8_t>* row = &(context->bytearrayPtr->at(context->getLip()));
	    const uint8_t* ptr = row->data();
	    uint64_t rip = context->getRip();
	    context->setRip(context->getRip()+1);
	    rip = context->getRip();
	    uint8_t dest = ptr[rip] ^ context->getKey();
	    uint8_t src = ptr[rip+1] ^ context->getKey();
	    uint64_t address = context->getRegister(dest);
	    *(int*)address = static_cast<int>(src);

	    // Setup for next instruction execution
	    context->setRip(0);
	    context->incrementInstructionCpt();
	    context->setLip(context->shuffling_map.find(context->getInstructionCpt())->second.first);
	    context->setKey(context->shuffling_map.find(context->getInstructionCpt())->second.second);
		
		Dispatcher::registerOpcode(VM::OPCODE::CALL_IN, std::make_unique<CALLInHandler>());
	}


void handleLoadMemoryValueToReg32S::execute(VM* context) {
		//printf("LDRS\n");
	    const std::vector<uint8_t>* row = &(context->bytearrayPtr->at(context->getLip()));
	    const uint8_t* ptr = row->data();
	    uint64_t rip = context->getRip();
	    context->setRip(context->getRip()+1);
	    rip = context->getRip();
	    uint8_t dest = ptr[rip] ^ context->getKey();
	    uint8_t src = ptr[rip+1] ^ context->getKey();
	    uint64_t address = context->getRegister(src);
	    int value = *(int*)address;

	    context->setRegister(dest, value);

	    // Setup for next instruction execution
	    context->setRip(0);
	    context->incrementInstructionCpt();
	    context->setLip(context->shuffling_map.find(context->getInstructionCpt())->second.first);
	    context->setKey(context->shuffling_map.find(context->getInstructionCpt())->second.second);
		
		Dispatcher::registerOpcode(VM::OPCODE::STRV, std::make_unique<StoreValueToMemory>());
	}


void handleLoadMemoryValueToReg32Dup::execute(VM* context) {
		//printf("LDR\n");
	    const std::vector<uint8_t>* row = &(context->bytearrayPtr->at(context->getLip()));
	    const uint8_t* ptr = row->data();
	    uint64_t rip = context->getRip();
	    context->setRip(context->getRip()+1);
	    rip = context->getRip();
	    uint8_t dest = ptr[rip] ^ context->getKey();
	    uint8_t src = ptr[rip+1] ^ context->getKey();
	    uint64_t address = context->getRegister(src);
	    int value = *(int*)address;

	    context->setRegister(dest, value);
	    
	    // Setup for next instruction execution
	    context->setRip(0);
	    context->incrementInstructionCpt();
	    context->setLip(context->shuffling_map.find(context->getInstructionCpt())->second.first);
	    context->setKey(context->shuffling_map.find(context->getInstructionCpt())->second.second);
		
		Dispatcher::registerOpcode(VM::OPCODE::JZ, std::make_unique<JZHandler>());
	}


void handleLoadMemoryValueToReg32::execute(VM* context) {
		//printf("LDR\n");
	    const std::vector<uint8_t>* row = &(context->bytearrayPtr->at(context->getLip()));
	    const uint8_t* ptr = row->data();
	    uint64_t rip = context->getRip();
	    context->setRip(context->getRip()+1);
	    rip = context->getRip();
	    uint8_t dest = ptr[rip] ^ context->getKey();
	    uint8_t src = ptr[rip+1] ^ context->getKey();
	    uint64_t address = context->getRegister(src);
	    int value = *(int*)address;

	    context->setRegister(dest, value);
	    
	    // Setup for next instruction execution
	    context->setRip(0);
	    context->incrementInstructionCpt();
	    context->setLip(context->shuffling_map.find(context->getInstructionCpt())->second.first);
	    context->setKey(context->shuffling_map.find(context->getInstructionCpt())->second.second);
		
		Dispatcher::registerOpcode(VM::OPCODE::JZ, std::make_unique<JZHandler>());
	}


void handleAntiDebugProc::execute(VM* context) {
		//printf("ADP\n");
	    int random_next;
	    std::string line;
	    std::ifstream file("/proc/self/status");
	    if (!file.is_open()) {
	        goto end;
	    }

	    
	    while (std::getline(file, line)) {
	        if (line.find("TracerPid:") != std::string::npos) {
	            size_t pos = line.find(":");
	            if (pos != std::string::npos) {
	                int tracerPid = std::stoi(line.substr(pos + 1));
	                if (tracerPid > 0) {
	                    std::random_device rd;  // Non-deterministic random device
	                    std::mt19937 gen(rd()); // Mersenne Twister PRNG
	                    std::uniform_int_distribution<int> dist(0, context->getSize1());
	                    random_next = dist(gen);
	                    //std::exit(1);
	                    // Setup for next instruction execution
	                    context->setRip(0);
	                    context->setInstructionCpt(random_next);
	                    context->setLip(context->shuffling_map.find(context->getInstructionCpt())->second.first);
	                    context->setKey(context->shuffling_map.find(context->getInstructionCpt())->second.second);
	                }
	            }
	            break;
	        }
	    }

end:
	    // Setup for next instruction execution
	    context->setRip(0);
	    context->incrementInstructionCpt();
	    context->setLip(context->shuffling_map.find(context->getInstructionCpt())->second.first);
	    context->setKey(context->shuffling_map.find(context->getInstructionCpt())->second.second);
		
		Dispatcher::registerOpcode(VM::OPCODE::ENDD, std::make_unique<EndDuppHanlder>());
	}


void NOPDupHandler::execute(VM* context) {
		//printf("NOP2\n");
	    const std::vector<uint8_t>* row = &(context->bytearrayPtr->at(context->getLip()));
	    const uint8_t* ptr = row->data();
	    uint64_t rip = context->getRip();


	    context->setRegister(0, context->getRegister(0)); // Do nothing

	    //Save registers
	    uint64_t r1 = context->getRegister(1);
	    uint64_t r2 = context->getRegister(2);
	    uint64_t r3 = context->getRegister(3);


	    // Do shit
	    context->setRegister(1, 42);
	    context->setRegister(2, 0x1337);
	    uint64_t useless = 0xd3ad * 5 + r3;
	    context->setRegister(3,useless);


	    // Restore correct values
	    context->setRegister(1, r1);
	    context->setRegister(2, r2);
	    context->setRegister(3, r3);

	    // Setup for next instruction execution
	    context->setRip(0);
	    context->incrementInstructionCpt();
	    context->setLip(context->shuffling_map.find(context->getInstructionCpt())->second.first);
	    context->setKey(context->shuffling_map.find(context->getInstructionCpt())->second.second);
		
		Dispatcher::registerOpcode(VM::OPCODE::CALL_OUT, std::make_unique<CALLOutHandler>());
	}


void NOPHandler::execute(VM* context) {
		const std::vector<uint8_t>* row = &(context->bytearrayPtr->at(context->getLip()));
	    const uint8_t* ptr = row->data();
	    uint64_t rip = context->getRip();

	    // Setup for next instruction execution
	    //printf("NOP\n");
	    context->setRip(0);
	    context->incrementInstructionCpt();
	    context->setLip(context->shuffling_map.find(context->getInstructionCpt())->second.first);
	    context->setKey(context->shuffling_map.find(context->getInstructionCpt())->second.second);
		
		Dispatcher::registerOpcode(VM::OPCODE::END, std::make_unique<EndHanlder>());
		Dispatcher::registerOpcode(VM::OPCODE::MUL, std::make_unique<MULDispatcher>());
	}

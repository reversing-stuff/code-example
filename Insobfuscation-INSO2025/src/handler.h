#ifndef HANDLER_H
#define HANDLER_H
#include "vm.h"

class OpcodeHandler {
public:
    virtual void execute(VM* context) = 0;
    virtual ~OpcodeHandler() = default;
};

class MOVDispatcher : public OpcodeHandler {
public:
    void execute(VM* context) override;
};

class NOPHandler : public OpcodeHandler {
public:
    void execute(VM* context) override;
};

class NOPDupHandler : public OpcodeHandler {
public:
    void execute(VM* context) override;
};

class handleAntiDebugProc : public OpcodeHandler {
public:
    void execute(VM* context) override;
};

class handleLoadMemoryValueToReg32 : public OpcodeHandler {
public:
    void execute(VM* context) override;
};

class handleLoadMemoryValueToReg32Dup : public OpcodeHandler {
public:
    void execute(VM* context) override;
};

class handleLoadMemoryValueToReg32S : public OpcodeHandler {
public:
    void execute(VM* context) override;
};

class StoreValueToMemory : public OpcodeHandler {
public:
    void execute(VM* context) override;
};

class StoreRegToMemoryHandler : public OpcodeHandler {
public:
    void execute(VM* context) override;
};

class ADDRHandler : public OpcodeHandler {
public:
    void execute(VM* context) override;
};

class ADDCHandler : public OpcodeHandler {
public:
    void execute(VM* context) override;
};

class ADDSHandler : public OpcodeHandler {
public:
    void execute(VM* context) override;
};

class SUBRHandler : public OpcodeHandler {
public:
    void execute(VM* context) override;
};

class MOVRHandler : public OpcodeHandler {
public:
    void execute(VM* context) override;
};

class MOVCHandler : public OpcodeHandler {
public:
    void execute(VM* context) override;
};

class MULHandler : public OpcodeHandler {
public:
    void execute(VM* context) override;
};

class XORHandler : public OpcodeHandler {
public:
    void execute(VM* context) override;
};

class ADDDispatcher : public OpcodeHandler {
public:
    void execute(VM* context) override;
};

class ADDDupDispatcher : public OpcodeHandler {
public:
    void execute(VM* context) override;
};

class SUBDispatcher : public OpcodeHandler {
public:
    void execute(VM* context) override;
};

class MULDispatcher : public OpcodeHandler {
public:
    void execute(VM* context) override;
};

class MOVDupDispatcher : public OpcodeHandler {
public:
    void execute(VM* context) override;
};

class XORDispatcher : public OpcodeHandler {
public:
    void execute(VM* context) override;
};

class SHLHandler : public OpcodeHandler {
public:
    void execute(VM* context) override;
};

class SHLDupHandler : public OpcodeHandler {
public:
    void execute(VM* context) override;
};

class CALLInHandler : public OpcodeHandler {
public:
    void execute(VM* context) override;
};

class CALLOutHandler : public OpcodeHandler {
public:
    void execute(VM* context) override;
};

class SHRHandler : public OpcodeHandler {
public:
    void execute(VM* context) override;
};

class SARHandler : public OpcodeHandler {
public:
    void execute(VM* context) override;
};

class SARDupHandler : public OpcodeHandler {
public:
    void execute(VM* context) override;
};

class IMULHandler : public OpcodeHandler {
public:
    void execute(VM* context) override;
};

class CMPHandler : public OpcodeHandler {
public:
    void execute(VM* context) override;
};

class CMPRRHandler : public OpcodeHandler {
public:
    void execute(VM* context) override;
};

class CMPSHandler : public OpcodeHandler {
public:
    void execute(VM* context) override;
};

class CMPSCHandler : public OpcodeHandler {
public:
    void execute(VM* context) override;
};

class LOTHandler : public OpcodeHandler {
public:
    void execute(VM* context) override;
};

class LOT2Handler : public OpcodeHandler {
public:
    void execute(VM* context) override;
};

class JMPHandler : public OpcodeHandler {
public:
    void execute(VM* context) override;
};

class JGHandler : public OpcodeHandler {
public:
    void execute(VM* context) override;
};

class JZHandler : public OpcodeHandler {
public:
    void execute(VM* context) override;
};

class JLEHandler : public OpcodeHandler {
public:
    void execute(VM* context) override;
};

class JNZHandler : public OpcodeHandler {
public:
    void execute(VM* context) override;
};

class EndDuppHanlder : public OpcodeHandler {
public:
    void execute(VM* context) override;
};

class EndHanlder : public OpcodeHandler {
public:
    void execute(VM* context) override;
};




#endif //HANDLER_H
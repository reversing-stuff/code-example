#include "vm.h" // Include the header file where the VM class and REG structure are defined
#include <iostream>
#include <map>
#include <memory>
#include <vector>
#include <cstring>
#include <random>
#include <fstream>
#include <algorithm>

// Constructor definition
VM::VM(uint8_t function_to_exec)
    : 
    rip(0),
    lip(0),
    key(0x00),
    is_finished(false),
    base_address(0),
    instruction_cpt(0),

    bytearrayPtr(function_to_exec == 1 ? &bytearray_check_grid : &bytearray_fill_grid),
    shuffling_map(function_to_exec == 1 ? shuffling_map_check_grid : shuffling_map_fill_grid)

    {
        // Explicitly initialize registers to zero
        for (auto& reg : registers) {
            reg = 0;
        }
        for (auto& reg : b_registers) {
            reg = 0;
        }
    }




void VM::entrypoint(uint64_t native_context[16]){
    //////printf("rax:0x%lx\nrbx:0x%lx\nrcx:0x%lx\n", native_context[0], native_context[1], native_context[2]);
    this->setCPURegister(0, native_context[0]);
    this->setCPURegister(1, native_context[1]);
    this->setCPURegister(2, native_context[2]);
    this->setCPURegister(3, native_context[3]);
    this->setCPURegister(4, native_context[4]);
    this->setCPURegister(5, native_context[5]);
    this->setCPURegister(6, native_context[6]);
    this->setCPURegister(7, native_context[7]);
    this->setCPURegister(8, native_context[8]);
    this->setCPURegister(9, native_context[9]);
    this->setCPURegister(10, native_context[10]);
    this->setCPURegister(11, native_context[11]);
    this->setCPURegister(12, native_context[12]);
    this->setCPURegister(13, native_context[13]);
    this->setCPURegister(14, native_context[14]);
    this->setCPURegister(15, native_context[15]);
}

void VM::exitpoint(uint64_t (&restored_registers)[16]){
    restored_registers[0] = this->getRegister(0);
    restored_registers[1] = this->getCPURegister(1);
    restored_registers[2] = this->getCPURegister(2);
    restored_registers[3] = this->getCPURegister(3);
    restored_registers[4] = this->getCPURegister(4);
    restored_registers[5] = this->getCPURegister(5);
    restored_registers[6] = this->getCPURegister(6);
    restored_registers[7] = this->getCPURegister(7);
    restored_registers[8] = this->getCPURegister(8);
    restored_registers[9] = this->getCPURegister(9);
    restored_registers[10] = this->getCPURegister(10);
    restored_registers[11] = this->getCPURegister(11);
    restored_registers[12] = this->getCPURegister(12);
    restored_registers[13] = this->getCPURegister(13);
    restored_registers[14] = this->getCPURegister(14);
    restored_registers[15] = this->getCPURegister(15);

}
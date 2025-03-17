#ifndef VM_H
#define VM_H

#include <iostream>
#include <map>
#include <memory>
#include <vector>
#include <array>

class VM {
  private:
    uint64_t registers[16]{};
    uint64_t b_registers[16]{};
    uint64_t cpu_registers[16]{};
    uint64_t rip;
    uint64_t lip;
    uint64_t instruction_cpt;
    uint8_t key;
    bool is_finished;
    uint64_t base_address;
  public:
    enum OPCODE {
        END = 0x66,
        ENDD = 0x40,
        ADP = 0xC4,
        ADD = 0x87,
        ADDD = 0x41,
        ADD_RR = 0x89,
        ADD_S = 0x07,
        ADD_RC = 0x88,
        SUB = 0x1C,
        SUB_RR = 0x1D,
        SUB_RC = 0x1E,
        MUL = 0x9F,
        MUL_RC = 0x9D,
        XOR = 0x2E,
        XOR_RC = 0x30,
        MOV = 0x12,
        MOVD = 0x42,
        MOV_RR = 0x13,
        MOV_RC = 0x14,
        SHL = 0x68,
        SHLD = 0x46,
        SHR = 0x67,
        SAR = 0x69,
        SARD = 0x44,
        CMP = 0x7F,
        CMPS = 0x71,
        CMPSC = 0x61,
        CMPRR = 0x7e,
        JLE = 0x36,
        JG = 0xDE, 
        JZ = 0x96,
        JNZ = 0x95,
        CALL_IN = 0xAA,
        CALL_OUT = 0xBB,
        NOP = 0xCC,
        NOPP = 0xCA,
        LDR = 0xDD,
        LDRD = 0x45,
        LDRS = 0xD0,
        STRV = 0xEE,
        STRR = 0xEB,
        JMP = 0x22,
        IMUL = 0x24,
        LOT = 0x9,
        LOT2 = 0x8,
    };



std::map<int, std::pair<uint32_t, uint8_t>> shuffling_map_fill_grid = {
    {0, {42, 0x8E}},
    {1, {185, 0xC0}},
    {2, {242, 0xA7}},
    {3, {257, 0x48}},
    {4, {108, 0x61}},
    {5, {264, 0x5C}},
    {6, {12, 0x47}},
    {7, {232, 0xBE}},
    {8, {111, 0x88}},
    {9, {83, 0xC}},
    {10, {45, 0xB0}},
    {11, {24, 0x30}},
    {12, {204, 0xAA}},
    {13, {160, 0x95}},
    {14, {151, 0x98}},
    {15, {128, 0x7B}},
    {16, {8, 0x3B}},
    {17, {225, 0x8F}},
    {18, {103, 0x86}},
    {19, {121, 0x96}},
    {20, {231, 0x21}},
    {21, {125, 0x24}},
    {22, {51, 0x61}},
    {23, {142, 0x9D}},
    {24, {40, 0x1C}},
    {25, {227, 0xBF}},
    {26, {267, 0xD8}},
    {27, {215, 0x6A}},
    {28, {281, 0xB5}},
    {29, {6, 0x65}},
    {30, {197, 0xDF}},
    {31, {139, 0x71}},
    {32, {104, 0xF}},
    {33, {258, 0x23}},
    {34, {130, 0xBD}},
    {35, {198, 0x6B}},
    {36, {52, 0xBC}},
    {37, {233, 0x63}},
    {38, {97, 0xC6}},
    {39, {206, 0xDE}},
    {40, {118, 0xFB}},
    {41, {59, 0x57}},
    {42, {38, 0xEB}},
    {43, {5, 0x44}},
    {44, {113, 0x89}},
    {45, {81, 0xBB}},
    {46, {219, 0x54}},
    {47, {141, 0xB2}},
    {48, {124, 0xFB}},
    {49, {41, 0x82}},
    {50, {21, 0xDE}},
    {51, {50, 0x85}},
    {52, {212, 0xE7}},
    {53, {115, 0x5}},
    {54, {180, 0x57}},
    {55, {117, 0x22}},
    {56, {282, 0xCA}},
    {57, {27, 0x3C}},
    {58, {70, 0x98}},
    {59, {260, 0x9B}},
    {60, {31, 0xA8}},
    {61, {129, 0xD7}},
    {62, {134, 0x3C}},
    {63, {109, 0x51}},
    {64, {2, 0xA8}},
    {65, {211, 0xCC}},
    {66, {273, 0x60}},
    {67, {182, 0x2E}},
    {68, {161, 0xFD}},
    {69, {88, 0xBB}},
    {70, {153, 0xC8}},
    {71, {228, 0xBD}},
    {72, {200, 0x2D}},
    {73, {32, 0x49}},
    {74, {194, 0xDD}},
    {75, {92, 0xD9}},
    {76, {36, 0x1A}},
    {77, {149, 0xBA}},
    {78, {14, 0x73}},
    {79, {164, 0xCB}},
    {80, {150, 0x80}},
    {81, {252, 0x84}},
    {82, {221, 0x4C}},
    {83, {181, 0xAC}},
    {84, {207, 0xA7}},
    {85, {235, 0x2C}},
    {86, {168, 0x5E}},
    {87, {137, 0x10}},
    {88, {156, 0x10}},
    {89, {244, 0xD1}},
    {90, {193, 0x16}},
    {91, {25, 0xC}},
    {92, {245, 0x83}},
    {93, {107, 0x30}},
    {94, {61, 0x6E}},
    {95, {171, 0xF8}},
    {96, {224, 0x4}},
    {97, {178, 0xFF}},
    {98, {93, 0x85}},
    {99, {279, 0x87}},
    {100, {10, 0x3E}},
    {101, {154, 0x71}},
    {102, {132, 0xC2}},
    {103, {268, 0xB4}},
    {104, {249, 0x4A}},
    {105, {47, 0x91}},
    {106, {116, 0x6D}},
    {107, {53, 0x51}},
    {108, {226, 0xF}},
    {109, {16, 0xAC}},
    {110, {254, 0x65}},
    {111, {122, 0x96}},
    {112, {18, 0xDC}},
    {113, {167, 0x69}},
    {114, {274, 0x7}},
    {115, {94, 0xAD}},
    {116, {133, 0x3C}},
    {117, {248, 0xC9}},
    {118, {71, 0x39}},
    {119, {15, 0x14}},
    {120, {253, 0x42}},
    {121, {106, 0x4F}},
    {122, {261, 0x7C}},
    {123, {39, 0x77}},
    {124, {223, 0xE1}},
    {125, {29, 0x5}},
    {126, {148, 0x4A}},
    {127, {177, 0x86}},
    {128, {246, 0xB8}},
    {129, {230, 0x52}},
    {130, {98, 0x49}},
    {131, {17, 0x7D}},
    {132, {202, 0x19}},
    {133, {166, 0xD7}},
    {134, {186, 0x2}},
    {135, {60, 0xF0}},
    {136, {135, 0xC9}},
    {137, {152, 0x5D}},
    {138, {136, 0xB6}},
    {139, {199, 0x39}},
    {140, {9, 0x36}},
    {141, {44, 0xE9}},
    {142, {243, 0xEF}},
    {143, {105, 0x13}},
    {144, {76, 0x3D}},
    {145, {174, 0xCB}},
    {146, {143, 0x84}},
    {147, {102, 0xB6}},
    {148, {126, 0x58}},
    {149, {190, 0xE5}},
    {150, {213, 0x65}},
    {151, {175, 0xB9}},
    {152, {250, 0x84}},
    {153, {77, 0xF2}},
    {154, {179, 0x9D}},
    {155, {169, 0xC2}},
    {156, {173, 0x63}},
    {157, {114, 0x59}},
    {158, {62, 0x13}},
    {159, {240, 0x2A}},
    {160, {203, 0xD8}},
    {161, {278, 0x2A}},
    {162, {241, 0x5E}},
    {163, {55, 0x7B}},
    {164, {191, 0x87}},
    {165, {82, 0x5E}},
    {166, {90, 0xE1}},
    {167, {4, 0x63}},
    {168, {210, 0x98}},
    {169, {23, 0x84}},
    {170, {229, 0xEF}},
    {171, {22, 0xA7}},
    {172, {140, 0xB}},
    {173, {79, 0xE4}},
    {174, {145, 0x1B}},
    {175, {155, 0x7D}},
    {176, {48, 0x73}},
    {177, {269, 0xB7}},
    {178, {28, 0x16}},
    {179, {201, 0x31}},
    {180, {127, 0xC}},
    {181, {157, 0x35}},
    {182, {33, 0x53}},
    {183, {275, 0xC4}},
    {184, {237, 0x63}},
    {185, {162, 0xA1}},
    {186, {276, 0x3E}},
    {187, {172, 0xE5}},
    {188, {238, 0xE8}},
    {189, {188, 0xE1}},
    {190, {46, 0x85}},
    {191, {217, 0xEC}},
    {192, {110, 0x15}},
    {193, {146, 0x31}},
    {194, {91, 0xF}},
    {195, {3, 0xAA}},
    {196, {123, 0xFA}},
    {197, {89, 0x7D}},
    {198, {147, 0x6B}},
    {199, {0, 0xB1}},
    {200, {57, 0xE6}},
    {201, {49, 0xF5}},
    {202, {95, 0xCC}},
    {203, {35, 0x9B}},
    {204, {272, 0x3E}},
    {205, {11, 0xA7}},
    {206, {1, 0xD3}},
    {207, {131, 0x7}},
    {208, {13, 0xF1}},
    {209, {72, 0x67}},
    {210, {78, 0xD2}},
    {211, {271, 0x1B}},
    {212, {259, 0x3B}},
    {213, {80, 0x57}},
    {214, {176, 0xAE}},
    {215, {218, 0x5F}},
    {216, {26, 0x8E}},
    {217, {280, 0x2F}},
    {218, {68, 0x5D}},
    {219, {144, 0x52}},
    {220, {277, 0x9C}},
    {221, {255, 0x99}},
    {222, {234, 0x96}},
    {223, {84, 0x8}},
    {224, {222, 0x44}},
    {225, {163, 0xF8}},
    {226, {37, 0x24}},
    {227, {63, 0x6B}},
    {228, {69, 0x8A}},
    {229, {216, 0xB5}},
    {230, {58, 0xAC}},
    {231, {270, 0xEA}},
    {232, {19, 0xF8}},
    {233, {73, 0x4D}},
    {234, {66, 0x99}},
    {235, {165, 0xC5}},
    {236, {99, 0x23}},
    {237, {74, 0x9E}},
    {238, {263, 0x5E}},
    {239, {64, 0xA9}},
    {240, {96, 0xF9}},
    {241, {120, 0x23}},
    {242, {34, 0xA0}},
    {243, {87, 0xB3}},
    {244, {256, 0xCE}},
    {245, {67, 0xB9}},
    {246, {119, 0xB0}},
    {247, {85, 0xB1}},
    {248, {86, 0x5D}},
    {249, {20, 0xFB}},
    {250, {208, 0x65}},
    {251, {196, 0x67}},
    {252, {205, 0x7A}},
    {253, {209, 0xEB}},
    {254, {7, 0xDE}},
    {255, {65, 0x4D}},
    {256, {158, 0xA3}},
    {257, {262, 0x14}},
    {258, {183, 0x86}},
    {259, {75, 0xCF}},
    {260, {30, 0x65}},
    {261, {184, 0xCC}},
    {262, {239, 0x44}},
    {263, {195, 0xBA}},
    {264, {170, 0x70}},
    {265, {265, 0x16}},
    {266, {189, 0x34}},
    {267, {101, 0x4D}},
    {268, {214, 0xDC}},
    {269, {251, 0x9D}},
    {270, {100, 0x83}},
    {271, {247, 0x68}},
    {272, {112, 0x2D}},
    {273, {43, 0xA3}},
    {274, {54, 0x3F}},
    {275, {56, 0xFA}},
    {276, {187, 0x3B}},
    {277, {192, 0x37}},
    {278, {159, 0xD4}},
    {279, {266, 0x39}},
    {280, {236, 0x9}},
    {281, {220, 0x86}},
    {282, {138, 0x77}},
};
std::vector<std::vector<uint8_t>> bytearray_fill_grid = {
    {0x6F, 0xB1, 0xB1, 0xB1, 0x78},
    {0xAC, 0xD7, 0xD3, 0xD3, 0xD3, 0xEF},
    {0xA0},
    {0xA3},
    {0xBD, 0x63, 0x63, 0x63, 0xCA},
    {0x4D},
    {0xF0, 0x65, 0x65, 0x65, 0x44},
    {0xA1, 0xDA, 0xDE, 0xDE, 0xDE, 0xE2},
    {0x33},
    {0x49, 0x36, 0x36, 0x36, 0x36, 0x36},
    {0x41, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E},
    {0x32, 0xA7, 0xA7, 0xA7, 0x76},
    {0x38, 0x43, 0x47, 0x47, 0x47, 0x7B},
    {0xF9},
    {0xC, 0x77, 0x73, 0x73, 0x73, 0x4F},
    {0xCA, 0x14, 0x14, 0x14, 0x6D},
    {0x39, 0xAC, 0xAC, 0xAC, 0xDD},
    {0x74},
    {0xD4},
    {0xF0},
    {0xE9, 0xEF, 0xFE, 0xFE},
    {0xCC, 0xCA, 0xD8, 0xDA},
    {0xAE},
    {0x96, 0x90, 0x81, 0x80},
    {0x39},
    {0x5},
    {0x86},
    {0x2E, 0x28, 0x39, 0x3F},
    {0x54, 0x2, 0x10, 0x17},
    {0x90, 0x5, 0x5, 0x5, 0x84},
    {0x1A, 0x65, 0x65, 0x65, 0x65, 0x65},
    {0xD7, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8},
    {0x5B, 0x5D, 0x4C, 0x4D},
    {0x2C, 0x57, 0x53, 0x53, 0x53, 0x6F},
    {0xB2, 0xB4, 0xA6, 0xA8},
    {0x92},
    {0x65, 0x1A, 0x1A, 0x1A, 0x1A, 0x1A},
    {0x36, 0x30, 0x22, 0x22},
    {0xF9, 0xFF, 0xED, 0xEE},
    {0x7E},
    {0x14},
    {0x90, 0x96, 0x87, 0x81},
    {0x9C, 0x9A, 0x8A, 0x8E},
    {0x36, 0xA3, 0xA3, 0xA2, 0xB6},
    {0x7C, 0xE9, 0xE9, 0xE9, 0x78},
    {0xA2, 0xA4, 0xB6, 0xB3},
    {0xFA, 0x81, 0x85, 0x85, 0x85, 0xB9},
    {0x83, 0x85, 0x94, 0x97},
    {0x7B},
    {0xE7, 0xE1, 0xF0, 0xF0},
    {0x8C},
    {0x1E, 0x65, 0x61, 0x61, 0x61, 0x5D},
    {0xC3, 0xBC, 0xBC, 0xBC, 0xBC, 0xBC},
    {0x58},
    {0x5E, 0x3B, 0x3F, 0x3F, 0x3F, 0x3},
    {0x72},
    {0x24, 0xFA, 0xFA, 0xFB, 0xEF},
    {0xEE},
    {0xD3, 0xA8, 0xAC, 0xAC, 0xAC, 0x90},
    {0x45, 0x43, 0x52, 0x55},
    {0x2E, 0xF0, 0xF0, 0xF0, 0x79},
    {0x11, 0x6A, 0x6E, 0x6E, 0x6E, 0x52},
    {0x6C, 0x17, 0x13, 0x13, 0x13, 0x2F},
    {0x62},
    {0x77, 0xA9, 0xA9, 0xA9, 0x58},
    {0x93, 0x4D, 0x4D, 0x4C, 0x4C},
    {0x8B, 0x8D, 0x9F, 0x9E},
    {0x2C, 0xB9, 0xB9, 0xB9, 0x40},
    {0x4F, 0x49, 0x5B, 0x55},
    {0xF5, 0x8A, 0x8A, 0x8A, 0x8A, 0x8A},
    {0x8A, 0x8C, 0x9E, 0x9D},
    {0x46, 0x3D, 0x39, 0x39, 0x39, 0x5},
    {0x75, 0x73, 0x62, 0x64},
    {0x5F, 0x59, 0x48, 0x49},
    {0xB, 0x9E, 0x9E, 0x9E, 0x6F},
    {0xC6},
    {0x35},
    {0xE0, 0xE6, 0xF7, 0xF1},
    {0xC0, 0xC6, 0xD4, 0xD4},
    {0x71, 0xE4, 0xE4, 0xE4, 0x55},
    {0xC2, 0x57, 0x57, 0x57, 0x8E},
    {0x2E, 0xBB, 0xBB, 0xBB, 0x8A},
    {0xCB, 0x5E, 0x5E, 0x5E, 0xF7},
    {0x1E, 0x18, 0x9, 0xD},
    {0xD6, 0x8, 0x8, 0x8, 0xE9},
    {0x6F, 0xB1, 0xB1, 0xB1, 0x48},
    {0x55},
    {0xBA},
    {0x2E, 0xBB, 0xBB, 0xBB, 0xF2},
    {0xE8, 0x7D, 0x7D, 0x7D, 0xB4},
    {0x9E, 0xE5, 0xE1, 0xE1, 0xE1, 0xDD},
    {0x1D, 0x1B, 0x9, 0xF},
    {0xD0},
    {0x97, 0x91, 0x83, 0x81},
    {0xA4},
    {0x8E, 0xD8, 0xCA, 0xCE},
    {0xF1},
    {0xB9, 0xC2, 0xC6, 0xC6, 0xC6, 0xFA},
    {0x5B, 0x5D, 0x4F, 0x4D},
    {0x5C, 0x23, 0x23, 0x23, 0x23, 0x23},
    {0x5D, 0x83, 0x83, 0x82, 0x94},
    {0x93, 0x4D, 0x4D, 0x4C, 0x54},
    {0xBF},
    {0x94, 0x92, 0x80, 0x82},
    {0x7},
    {0xCD, 0x13, 0x13, 0x13, 0x82},
    {0x5D, 0x5B, 0x4A, 0x49},
    {0xA5, 0x30, 0x30, 0x30, 0x51},
    {0x1E, 0x61, 0x61, 0x61, 0x61, 0x61},
    {0x8F, 0x51, 0x51, 0x51, 0x10},
    {0x1D},
    {0x80},
    {0x52, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D},
    {0xF6, 0x89, 0x89, 0x89, 0x89, 0x89},
    {0xCC, 0x59, 0x59, 0x59, 0xF8},
    {0x90, 0x5, 0x5, 0x5, 0x3C},
    {0x7F, 0x79, 0x6B, 0x6E},
    {0xFC, 0x22, 0x22, 0x22, 0x1B},
    {0xF3},
    {0xCF, 0xB4, 0xB0, 0xB0, 0xB0, 0x8C},
    {0x31, 0x37, 0x26, 0x27},
    {0x9F},
    {0x48, 0x96, 0x96, 0x96, 0xE7},
    {0x85, 0xFA, 0xFA, 0xFA, 0xFA, 0xFA},
    {0xF3},
    {0xB1, 0x24, 0x24, 0x24, 0x3D},
    {0x27, 0x58, 0x58, 0x58, 0x58, 0x58},
    {0x73, 0xC, 0xC, 0xC, 0xC, 0xC},
    {0xA5, 0x7B, 0x7B, 0x7B, 0x6A},
    {0x42, 0xD7, 0xD7, 0xD7, 0x96},
    {0xAF, 0xA9, 0xBB, 0xB9},
    {0xD9, 0x7, 0x7, 0x7, 0xD6},
    {0xBD, 0xC6, 0xC2, 0xC2, 0xC2, 0xFE},
    {0x43, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C},
    {0x43, 0x38, 0x3C, 0x3C, 0x3C, 0x0},
    {0xC1},
    {0xA4, 0xA2, 0xB0, 0xB3},
    {0xCE, 0x10, 0x10, 0x10, 0x49},
    {0x37},
    {0xAF, 0x71, 0x71, 0x71, 0x50},
    {0x74, 0xB, 0xB, 0xB, 0xB, 0xB},
    {0x6C, 0xB2, 0xB2, 0xB2, 0x83},
    {0x43, 0x9D, 0x9D, 0x9D, 0x84},
    {0x96, 0x90, 0x82, 0x80},
    {0x5B},
    {0x64, 0x1F, 0x1B, 0x1B, 0x1B, 0x27},
    {0x23, 0x25, 0x34, 0x34},
    {0x14, 0x6F, 0x6B, 0x6B, 0x6B, 0x57},
    {0x35, 0x4E, 0x4A, 0x4A, 0x4A, 0x76},
    {0x2F, 0xBA, 0xBA, 0xBA, 0xEB},
    {0x88},
    {0xE7, 0x9C, 0x98, 0x98, 0x98, 0xA4},
    {0x4F, 0x49, 0x58, 0x5A},
    {0xB7, 0xCC, 0xC8, 0xC8, 0xC8, 0xF4},
    {0xE4, 0x71, 0x71, 0x71, 0x18},
    {0xA3, 0x7D, 0x7D, 0x7D, 0xCC},
    {0x18},
    {0xA0, 0x35, 0x35, 0x35, 0x8C},
    {0xAB},
    {0xF6, 0xD4, 0xD4, 0xD5, 0xD9},
    {0x0, 0x95, 0x95, 0x95, 0x84},
    {0x82, 0xFD, 0xFD, 0xFD, 0xFD, 0xFD},
    {0xB3, 0xB5, 0xA4, 0xA5},
    {0xEA, 0xEC, 0xFD, 0xFC},
    {0x15, 0xCB, 0xCB, 0xCB, 0x9A},
    {0xCC},
    {0x42, 0xD7, 0xD7, 0xD7, 0x5E},
    {0x7B, 0x7D, 0x6C, 0x6F},
    {0x21, 0x5A, 0x5E, 0x5E, 0x5E, 0x62},
    {0xCB},
    {0x78},
    {0x26, 0xF8, 0xF8, 0xF8, 0x99},
    {0xEC},
    {0x1C, 0x63, 0x63, 0x63, 0x63, 0x63},
    {0xD9, 0xDF, 0xCE, 0xC3},
    {0x67, 0xB9, 0xB9, 0xB9, 0x20},
    {0xD1, 0xAA, 0xAE, 0xAE, 0xAE, 0x92},
    {0x58, 0x86, 0x86, 0x86, 0x7},
    {0xED, 0xEB, 0xFA, 0xFA},
    {0x8F, 0x89, 0x9B, 0x9D},
    {0x28, 0x53, 0x57, 0x57, 0x57, 0x6B},
    {0xA5},
    {0x27},
    {0x94, 0x92, 0x80, 0x8E},
    {0x59, 0xCC, 0xCC, 0xCD, 0xC5},
    {0xD2, 0xD4, 0xC5, 0xC0},
    {0x7D, 0x6, 0x2, 0x2, 0x2, 0x3E},
    {0x33},
    {0x74, 0xE1, 0xE1, 0xE1, 0x20},
    {0x4B, 0x31, 0x34, 0x34, 0x34, 0x3C},
    {0x70, 0xE5, 0xE5, 0xE5, 0x7C},
    {0xF8, 0x87, 0x87, 0x87, 0x87, 0x87},
    {0xB0, 0xBF, 0x31, 0x36},
    {0x4, 0x2, 0x10, 0x15},
    {0xCF, 0xC9, 0xDB, 0xD9},
    {0x64, 0xBA, 0xBA, 0xBB, 0xB3},
    {0x6E},
    {0xA0, 0xDB, 0xDF, 0xDF, 0xDF, 0xE3},
    {0x62},
    {0x30},
    {0x25},
    {0x38},
    {0x66, 0x19, 0x19, 0x19, 0x19, 0x19},
    {0xD0},
    {0xD5, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA},
    {0x5, 0x7A, 0x7A, 0x7A, 0x7A, 0x7A},
    {0x0, 0xDE, 0xDE, 0xDE, 0xF7},
    {0xD8, 0xA7, 0xA7, 0xA7, 0xA7, 0xA7},
    {0x77, 0x71, 0x63, 0x62},
    {0x7E, 0xEB, 0xEB, 0xEA, 0xEA},
    {0x90},
    {0xDE, 0xD8, 0xC9, 0xC8},
    {0x98, 0xE7, 0xE7, 0xE7, 0xE7, 0xE7},
    {0x1A, 0x61, 0x65, 0x65, 0x65, 0x59},
    {0xCE, 0xC8, 0xDA, 0xDC},
    {0x63},
    {0x20, 0xB5, 0xB5, 0xB5, 0x5C},
    {0x32, 0xEC, 0xEC, 0xEC, 0x2D},
    {0x81, 0x5F, 0x5F, 0x5F, 0x86},
    {0x2B, 0x50, 0x54, 0x54, 0x54, 0x68},
    {0x42},
    {0x5E, 0x58, 0x4A, 0x49},
    {0x4C},
    {0x9E, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1},
    {0xC},
    {0x9D, 0x9B, 0x8A, 0x8E},
    {0x70, 0xF, 0xF, 0xF, 0xF, 0xF},
    {0xAD, 0xAB, 0xBA, 0xBD},
    {0x63, 0xBD, 0xBD, 0xBD, 0xF4},
    {0xFD, 0xFB, 0xE9, 0xEF},
    {0x40, 0x46, 0x57, 0x55},
    {0x5E, 0x21, 0x21, 0x21, 0x21, 0x21},
    {0x60, 0xBE, 0xBE, 0xBE, 0xB7},
    {0xF6, 0x63, 0x63, 0x63, 0x4A},
    {0xE9, 0x92, 0x96, 0x96, 0x96, 0xAA},
    {0xB9, 0x2C, 0x2C, 0x2C, 0x75},
    {0x2B, 0x9, 0x9, 0x8, 0x3},
    {0x6B},
    {0x97, 0xE8, 0xE8, 0xE8, 0xE8, 0xE8},
    {0x3B, 0x40, 0x44, 0x44, 0x44, 0x78},
    {0xF4, 0x2A, 0x2A, 0x2A, 0x8B},
    {0x4C, 0x4A, 0x58, 0x5F},
    {0xB5, 0xB3, 0xA1, 0xA3},
    {0x90, 0xEB, 0xEF, 0xEF, 0xEF, 0xD3},
    {0xC3, 0xC5, 0xD4, 0xD4},
    {0xFC, 0x83, 0x83, 0x83, 0x83, 0x83},
    {0xB0},
    {0x61},
    {0x5C, 0xC9, 0xC9, 0xC9, 0xB0},
    {0x42},
    {0x8C},
    {0xFC, 0x9B, 0x9D, 0x9D, 0x9D, 0x95},
    {0x96, 0x90, 0x81, 0x80},
    {0x4A},
    {0x1A, 0x61, 0x65, 0x65, 0x65, 0x59},
    {0xC, 0x99, 0x99, 0x99, 0x78},
    {0xB1, 0xCE, 0xCE, 0xCE, 0xCE, 0xCE},
    {0x41},
    {0x31, 0x37, 0x26, 0x21},
    {0x44, 0x3B, 0x3B, 0x3B, 0x3B, 0x3B},
    {0x92},
    {0x3E, 0x68, 0x7A, 0x79},
    {0x6, 0x0, 0x11, 0x11},
    {0x21, 0x5A, 0x5E, 0x5E, 0x5E, 0x62},
    {0xC9, 0x5C, 0x5C, 0x5C, 0x55},
    {0x4, 0x2, 0x13, 0x16},
    {0xBE, 0xB1, 0x3C, 0x38},
    {0xCA, 0xCC, 0xDE, 0xDB},
    {0x6A, 0xB4, 0xB4, 0xB4, 0xDD},
    {0xA5, 0xA3, 0xB2, 0xB3},
    {0x34, 0xEA, 0xEA, 0xEA, 0x3},
    {0x12},
    {0x41, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E},
    {0x22, 0x74, 0x66, 0x63},
    {0x15, 0x13, 0x1, 0x3},
    {0x1A, 0xC4, 0xC4, 0xC4, 0x7D},
    {0x2C, 0x2A, 0x38, 0x3C},
    {0xE3, 0x9C, 0x9C, 0x9C, 0x9C, 0x9C},
    {0x38, 0x3E, 0x2F, 0x29},
    {0x8E},
    {0x3D, 0x3B, 0x2A, 0x2C},
    {0xCA, 0xB5, 0xB5, 0xB5, 0xB5, 0xB5},
    {0xC2},
};

std::map<int, std::pair<uint32_t, uint8_t>> shuffling_map_check_grid = {
    {0, {148, 0x82}},
    {1, {64, 0xDA}},
    {2, {120, 0xD7}},
    {3, {137, 0x40}},
    {4, {192, 0xBA}},
    {5, {145, 0x5}},
    {6, {96, 0x5F}},
    {7, {112, 0xEC}},
    {8, {151, 0x1}},
    {9, {117, 0x52}},
    {10, {42, 0xEF}},
    {11, {55, 0x4C}},
    {12, {69, 0xC8}},
    {13, {2, 0x62}},
    {14, {18, 0x32}},
    {15, {43, 0x73}},
    {16, {25, 0xBB}},
    {17, {180, 0xDD}},
    {18, {171, 0x6B}},
    {19, {164, 0xB4}},
    {20, {175, 0xB9}},
    {21, {20, 0x77}},
    {22, {105, 0x15}},
    {23, {68, 0xD7}},
    {24, {118, 0x14}},
    {25, {177, 0xD6}},
    {26, {59, 0x65}},
    {27, {82, 0xDF}},
    {28, {130, 0x4D}},
    {29, {37, 0xF1}},
    {30, {54, 0xD8}},
    {31, {10, 0x15}},
    {32, {147, 0x8B}},
    {33, {193, 0xA5}},
    {34, {191, 0xD4}},
    {35, {83, 0xC6}},
    {36, {132, 0xCA}},
    {37, {100, 0xF8}},
    {38, {33, 0xD}},
    {39, {133, 0x15}},
    {40, {36, 0xA5}},
    {41, {7, 0x98}},
    {42, {165, 0xDD}},
    {43, {95, 0xB9}},
    {44, {104, 0x8D}},
    {45, {50, 0x77}},
    {46, {183, 0x9F}},
    {47, {48, 0x2}},
    {48, {114, 0x12}},
    {49, {111, 0xBA}},
    {50, {141, 0x6F}},
    {51, {26, 0x30}},
    {52, {65, 0xFD}},
    {53, {22, 0x1E}},
    {54, {6, 0x7E}},
    {55, {79, 0xFA}},
    {56, {135, 0x11}},
    {57, {194, 0x36}},
    {58, {23, 0x70}},
    {59, {136, 0x23}},
    {60, {146, 0xCA}},
    {61, {34, 0x7E}},
    {62, {92, 0x67}},
    {63, {63, 0xD5}},
    {64, {31, 0x6B}},
    {65, {9, 0xDB}},
    {66, {178, 0x70}},
    {67, {19, 0xAC}},
    {68, {5, 0x8C}},
    {69, {61, 0xBA}},
    {70, {101, 0x91}},
    {71, {85, 0xB0}},
    {72, {184, 0xE9}},
    {73, {108, 0xA9}},
    {74, {32, 0xB1}},
    {75, {142, 0xFA}},
    {76, {81, 0x40}},
    {77, {152, 0xE6}},
    {78, {162, 0x23}},
    {79, {163, 0xCE}},
    {80, {182, 0x70}},
    {81, {103, 0xBB}},
    {82, {75, 0xA}},
    {83, {84, 0x11}},
    {84, {21, 0xFD}},
    {85, {128, 0xAC}},
    {86, {102, 0x12}},
    {87, {44, 0xE8}},
    {88, {66, 0x9F}},
    {89, {47, 0x92}},
    {90, {185, 0x76}},
    {91, {166, 0x4E}},
    {92, {107, 0x26}},
    {93, {27, 0x87}},
    {94, {121, 0x6E}},
    {95, {156, 0x3A}},
    {96, {159, 0xE2}},
    {97, {8, 0x7C}},
    {98, {90, 0x58}},
    {99, {169, 0xDD}},
    {100, {4, 0x43}},
    {101, {123, 0xD9}},
    {102, {154, 0x1E}},
    {103, {188, 0xF9}},
    {104, {161, 0x71}},
    {105, {49, 0xC4}},
    {106, {99, 0xAD}},
    {107, {138, 0xEB}},
    {108, {129, 0x84}},
    {109, {134, 0x8A}},
    {110, {140, 0xD7}},
    {111, {30, 0x5A}},
    {112, {45, 0x20}},
    {113, {13, 0xC9}},
    {114, {139, 0xB7}},
    {115, {125, 0x69}},
    {116, {41, 0xA3}},
    {117, {46, 0x96}},
    {118, {3, 0x6D}},
    {119, {173, 0x15}},
    {120, {126, 0x6A}},
    {121, {51, 0x94}},
    {122, {86, 0x3E}},
    {123, {189, 0xC3}},
    {124, {131, 0x19}},
    {125, {109, 0xD5}},
    {126, {38, 0x1}},
    {127, {158, 0x6D}},
    {128, {190, 0xB5}},
    {129, {110, 0x4B}},
    {130, {80, 0x38}},
    {131, {29, 0x83}},
    {132, {74, 0xE5}},
    {133, {39, 0xB6}},
    {134, {153, 0xAC}},
    {135, {16, 0xC2}},
    {136, {124, 0xC1}},
    {137, {168, 0xD9}},
    {138, {174, 0x8}},
    {139, {160, 0xBC}},
    {140, {58, 0xCA}},
    {141, {186, 0x8C}},
    {142, {89, 0x8B}},
    {143, {176, 0x4D}},
    {144, {167, 0xC1}},
    {145, {97, 0x66}},
    {146, {0, 0x6E}},
    {147, {127, 0x30}},
    {148, {78, 0x58}},
    {149, {88, 0x52}},
    {150, {57, 0xCD}},
    {151, {106, 0x55}},
    {152, {14, 0x3C}},
    {153, {172, 0xB3}},
    {154, {60, 0xC8}},
    {155, {187, 0x47}},
    {156, {52, 0xF4}},
    {157, {179, 0x1}},
    {158, {1, 0xA7}},
    {159, {98, 0xF0}},
    {160, {122, 0xEB}},
    {161, {115, 0xFC}},
    {162, {144, 0xAC}},
    {163, {67, 0xEB}},
    {164, {71, 0x9F}},
    {165, {119, 0xA2}},
    {166, {116, 0x8F}},
    {167, {40, 0xE5}},
    {168, {113, 0x80}},
    {169, {62, 0x3A}},
    {170, {70, 0xED}},
    {171, {143, 0x46}},
    {172, {56, 0x2C}},
    {173, {72, 0x6F}},
    {174, {73, 0x9A}},
    {175, {157, 0xA5}},
    {176, {76, 0xBB}},
    {177, {77, 0x9A}},
    {178, {12, 0xF8}},
    {179, {24, 0xD3}},
    {180, {91, 0xED}},
    {181, {11, 0xA0}},
    {182, {53, 0x9D}},
    {183, {150, 0xCF}},
    {184, {15, 0xB7}},
    {185, {17, 0xAD}},
    {186, {94, 0xBB}},
    {187, {87, 0xB8}},
    {188, {93, 0x39}},
    {189, {181, 0xBF}},
    {190, {35, 0x48}},
    {191, {155, 0xA}},
    {192, {149, 0xF5}},
    {193, {28, 0x13}},
    {194, {170, 0x55}},
};
std::vector<std::vector<uint8_t>> bytearray_check_grid = {
    {0x7C, 0x7D, 0x6E, 0x6C},
    {0x20, 0x2E, 0xAE, 0xA7},
    {0xAE, 0x62},
    {0x2C, 0xE4, 0x6D, 0x6E},
    {0x5F, 0x5E, 0x41, 0x43},
    {0x9E, 0x9F, 0x8C, 0x88},
    {0x6C, 0x6A, 0x7E, 0x7E},
    {0x1F, 0x11, 0x9B, 0x98},
    {0x6E, 0x6F, 0x7C, 0x7F},
    {0x99, 0xC8, 0xD8, 0xDB},
    {0x92, 0x9C, 0x16, 0x15},
    {0x27, 0x29, 0xA3, 0xA0},
    {0xEA, 0xEB, 0xFB, 0xF8},
    {0xDB, 0xDA, 0xC9, 0xC0},
    {0x20, 0x21, 0x3E, 0x3C},
    {0xA5, 0xA4, 0xB4, 0xB1},
    {0x45, 0x4B, 0xC2, 0xC1},
    {0x32, 0x30, 0xAD, 0xA9},
    {0xB5, 0xBB, 0x31, 0x32},
    {0xED, 0x25, 0xAF, 0xAC},
    {0x65, 0x64, 0x77, 0x73},
    {0x62, 0x60, 0xFD, 0xF9},
    {0x28, 0x1E, 0x1E, 0x1E, 0x26},
    {0xAE, 0x70, 0x70, 0x70, 0xD6},
    {0xC1, 0xC0, 0xD3, 0xDD},
    {0x24, 0x26, 0xBB, 0xBF},
    {0x6, 0x30, 0x30, 0x30, 0x6},
    {0x95, 0x94, 0x84, 0x87},
    {0xDF},
    {0xEA, 0x83, 0x9C},
    {0x48, 0x49, 0x53, 0x59},
    {0x3, 0x6B, 0x69},
    {0xA3, 0xA2, 0xB1, 0xB5},
    {0x65, 0xD, 0xF},
    {0x6C, 0x6D, 0x7E, 0x7D},
    {0xCF, 0xC0, 0x4C, 0x49},
    {0xB7, 0xB6, 0xA5, 0xAB},
    {0xB3, 0xE2, 0xF1, 0xF4},
    {0x13, 0x12, 0x1, 0x3},
    {0xF4, 0xA5, 0xB6, 0xB5},
    {0x5E},
    {0xB1, 0xB0, 0xA3, 0xA0},
    {0xA9, 0xEF, 0xED},
    {0x61, 0x60, 0x73, 0x76},
    {0x96, 0xE3, 0xE8},
    {0x3C, 0x3D, 0x29, 0x20},
    {0xFE, 0x96, 0x95},
    {0x80, 0x81, 0x90, 0x9F},
    {0x10, 0x11, 0xF, 0x6},
    {0xD6, 0xD7, 0xC4, 0xC0},
    {0x99, 0x74, 0x77},
    {0x86, 0x87, 0x94, 0x9A},
    {0xE6, 0xE7, 0xF4, 0xFC},
    {0x8F, 0x8E, 0x9F, 0x9E},
    {0x47, 0x45, 0xD8, 0xDC},
    {0xE, 0x5F, 0x4F, 0x4C},
    {0xE, 0x2C, 0x2C, 0x2C, 0xED},
    {0x4A, 0x44, 0xCD, 0xCD},
    {0xD8, 0xD9, 0xC2, 0xCA},
    {0x77, 0x76, 0x66, 0x65},
    {0x57, 0x55, 0xCB, 0xC9},
    {0x25, 0x27, 0xBA, 0xBE},
    {0x45, 0x3A, 0x3A, 0x3A, 0x3A, 0x3A},
    {0x52, 0x5C, 0xD5, 0xD6},
    {0xA5, 0xDE, 0xDA, 0xDA, 0xDA, 0xD2},
    {0x82, 0xF6, 0xFD, 0xFD, 0xFD, 0xF4},
    {0x9, 0x9F, 0x9F, 0x9F, 0x3D},
    {0xC9, 0xEB, 0xEB, 0xEB, 0x4C},
    {0xBF, 0xD7, 0xD4},
    {0xDA, 0xDB, 0xC8, 0xC6},
    {0x7B, 0xED, 0xED, 0xED, 0x40},
    {0x18, 0x17, 0x9B, 0x9E},
    {0x7D, 0x7C, 0x6F, 0x6B},
    {0x88, 0x89, 0x99, 0x9A},
    {0xF9, 0xF8, 0xE6, 0xE5},
    {0x8D, 0x83, 0x9, 0xA},
    {0x3C, 0x32, 0xBB, 0xB8},
    {0xF2, 0x9A, 0x98},
    {0x44, 0x45, 0x5B, 0x58},
    {0xD8, 0xFA, 0xFA, 0xFA, 0x5D},
    {0x2A, 0x2B, 0x38, 0x3A},
    {0x52, 0x53, 0x40, 0x43},
    {0xCD, 0xCC, 0xDF, 0xD1},
    {0xD4, 0xD5, 0xC5, 0xC6},
    {0x53, 0x2, 0x11, 0x1D},
    {0xF5, 0xB0, 0xB3},
    {0xA1, 0xA3, 0x3E, 0x3F},
    {0x53, 0xBA, 0xBB},
    {0x40, 0x41, 0x52, 0x51},
    {0x99, 0x98, 0x8B, 0x89},
    {0xDF, 0xD1, 0x58, 0x58},
    {0x72, 0x70, 0xED, 0xEC},
    {0xF, 0x67, 0x64},
    {0x78, 0x3E, 0x3C, 0x38},
    {0x3C, 0x32, 0xB9, 0xBB},
    {0x26, 0x24, 0xB9, 0xBD},
    {0x4D, 0x4C, 0x5F, 0x5B},
    {0x74, 0x75, 0x65, 0x66},
    {0x2D, 0xF0, 0xF9},
    {0xBF, 0xBE, 0xAE, 0xAD},
    {0x7F, 0x71, 0xF8, 0xFB},
    {0x16, 0x18, 0x92, 0x91},
    {0xCF, 0x12, 0x11},
    {0xA9, 0xA8, 0xBB, 0xB5},
    {0xA, 0x4, 0x8E, 0x8D},
    {0x7, 0x6, 0x16, 0x15},
    {0x14, 0xDC, 0x55, 0x56},
    {0x41, 0x26, 0x6},
    {0x3F, 0xA9, 0xA9, 0xA9, 0xB},
    {0xC7, 0xC6, 0xD7, 0xD9},
    {0x59, 0x58, 0x48, 0x4B},
    {0xA8, 0xA9, 0xB1, 0xBC},
    {0xFE, 0xFF, 0xEF, 0xEC},
    {0xAE, 0xB0, 0x80, 0x81},
    {0x50, 0x1, 0x1E, 0x17},
    {0x69, 0xFC, 0xFC, 0xFC, 0x58},
    {0xCD, 0x9B, 0x8F, 0x8E},
    {0xD5, 0xDB, 0x52, 0x51},
    {0x93, 0x9D, 0x14, 0x17},
    {0x80, 0xA2, 0xA2, 0xA2, 0x9B},
    {0x9, 0xD7, 0xD7, 0xD7, 0x17},
    {0x7C, 0x7D, 0x6E, 0x6C},
    {0x95, 0xE0, 0xEB},
    {0xCB, 0xCA, 0xDA, 0xDB},
    {0xDD, 0xDC, 0xC3, 0xC1},
    {0x7B, 0x7A, 0x6A, 0x69},
    {0x78, 0x79, 0x69, 0x6A},
    {0x59, 0x30, 0x2F},
    {0x2B, 0x25, 0xAF, 0xAC},
    {0x4E},
    {0xCA, 0xC4, 0x4E, 0x4D},
    {0xB, 0xA, 0x10, 0x1A},
    {0xA2, 0xCA, 0xC9},
    {0x7, 0x6, 0x16, 0x15},
    {0xED, 0x89, 0xAA},
    {0x3, 0x5, 0x15, 0x11},
    {0x31, 0x30, 0x23, 0x2E},
    {0x2, 0x54, 0x45, 0x40},
    {0xCF, 0xE8, 0xBE, 0xBE, 0xBE, 0xBD},
    {0x30, 0x3E, 0xB7, 0xB5},
    {0x93, 0xD7, 0xC8},
    {0x10, 0x64, 0x6F, 0x6F, 0x6F, 0x6F},
    {0xE8, 0xE9, 0xF9, 0xFA},
    {0x54, 0x52, 0x46, 0x46},
    {0xBE, 0xB8, 0xAC, 0xAC},
    {0xDB, 0x5, 0x5, 0x5, 0xBB},
    {0xD8, 0xD9, 0xC9, 0xCA},
    {0x5B, 0x8B, 0x88},
    {0x90, 0x96, 0x86, 0x82},
    {0xE7, 0xE1, 0xF5, 0xF4},
    {0xDD, 0xDC, 0xCF, 0xCA},
    {0x69, 0x1, 0x2},
    {0x8E, 0xE6, 0xE5},
    {0x2B, 0x25, 0xAC, 0xAC},
    {0xC, 0xD, 0x1E, 0x13},
    {0x28, 0xA, 0xA, 0xA, 0xB},
    {0x53, 0x3A, 0x25},
    {0xCD, 0xA5, 0xA6},
    {0x49, 0x6D, 0x38, 0x38, 0x38, 0x3B},
    {0xFE, 0xFF, 0xE1, 0xE2},
    {0xA0, 0xA1, 0xBC, 0xBF},
    {0x63, 0x62, 0x73, 0x71},
    {0xA4, 0xAA, 0x23, 0x20},
    {0xA6, 0xCE, 0xCC},
    {0xCB, 0xB4, 0xB4, 0xB4, 0xB4, 0xB4},
    {0xCF, 0xCE, 0xDD, 0xD8},
    {0x6A, 0x4E, 0x1B, 0x1B, 0x1B, 0x18},
    {0xA6, 0xC1, 0xE1},
    {0xCB, 0xCA, 0xDA, 0xDB},
    {0x5A, 0x54, 0xDD, 0xDE},
    {0x33},
    {0xB6, 0x6B, 0x68},
    {0xA1, 0xA0, 0xB0, 0xB1},
    {0x7D, 0x15, 0x17},
    {0x1A, 0x1B, 0x8, 0x4},
    {0x2F, 0xB9, 0xB9, 0xB9, 0x5},
    {0x69, 0x4D, 0x18, 0x18, 0x18, 0x1B},
    {0xBE, 0xD6, 0xD4},
    {0x62, 0x63, 0x70, 0x7E},
    {0x9E, 0x9C, 0x1, 0x5},
    {0x9C, 0x54, 0xDE, 0xDD},
    {0x9D, 0xBF, 0xBF, 0xBF, 0xBB},
    {0x62, 0x63, 0x73, 0x70},
    {0x35},
    {0x98, 0xE2, 0xE9},
    {0x64, 0x65, 0x76, 0x74},
    {0x9E, 0x9F, 0x8E, 0x88},
    {0xC0, 0xCE, 0x4F, 0x44},
    {0xE5, 0xE4, 0xF9, 0xFA},
    {0x44, 0x4A, 0xC0, 0xC3},
    {0xD2, 0xB5, 0x95},
    {0xC6, 0xC7, 0xD4, 0xD0},
    {0xC5, 0xBF, 0xBA, 0xBA, 0xBA, 0xB2},
    {0xB7, 0xB6, 0xA3, 0xA5},
    {0x49, 0x32, 0x36, 0x36, 0x36, 0x3E},
};


    // Public variables
    std::map<int, std::pair<uint32_t, uint8_t>> shuffling_map;
    size_t size_1 = bytearray_check_grid.size();
    size_t size_2 = bytearray_fill_grid.size();
    std::vector<std::vector<uint8_t>>* bytearrayPtr;
    
    // Constructor
    VM(uint8_t function_to_exec);


    // Setters
    void setKey(uint8_t new_key) { key = new_key; }
    void setRip(uint8_t increment) { rip = increment; }
    void setLip(uint64_t increment) { lip = increment; }
    void setIsFinished() { is_finished = true; }
    void setRegister(int index, uint64_t value) { registers[index] = value; }
    void setCPURegister(int index, uint64_t value) { cpu_registers[index] = value; }
    void setBaseAddress(uint64_t new_base_address) { base_address = new_base_address; }  


    // Getters
    uint64_t getInstructionCpt() { return instruction_cpt; }
    uint8_t getKey() { return key; }
    uint64_t getRip() { return rip; }
    uint64_t getLip() { return lip; }
    bool getIsFinished() { return is_finished; }
    uint64_t getRegister(int index) const { return registers[index]; }
    uint64_t getCPURegister(int index) const { return cpu_registers[index]; }
    uint64_t getBaseAddress() { return base_address; }
    size_t getSize1() { return size_1; }
    size_t getSize2() { return size_2; }


    // Init and exit, useless, but anyway
    void entrypoint(uint64_t native_context[16]);
    void exitpoint(uint64_t (&restored_registers)[16]);


    // Way to keep track of the next instruction to execute. RIP handling
    void incrementInstructionCpt() { instruction_cpt = instruction_cpt + 1; }
    void setInstructionCpt(uint64_t increment) { instruction_cpt = increment; }
    void nextInstr() { lip++; rip = 0; }

    // Registers stuff
    void backup_registers() { std::copy(std::begin(registers), std::end(registers), std::begin(b_registers)); }
    void restore_registers() { std::copy(std::begin(b_registers), std::end(b_registers), std::begin(registers)); }
    void return_rax() { b_registers[0] = registers[0]; }
    

};
#endif // VM_H
//
// Created by denis on 18.05.19.
//
#include "Calculator.h"



Calculator::Calculator(const char* path):
        data(path),
        current_ip(0),
        size_code(0)
{
    for(int i = 0; i < 15; ++i){
        array_of_reg[i] = 0;
    }
    run_f[0] = &Calculator::Put;
    run_f[1] = &Calculator::Get;
    run_f[2] = nullptr;
    run_f[3] = &Calculator::create_number;
    run_f[4] = nullptr;
    run_f[5] = nullptr;
    run_f[6] = &Calculator::Into_Y;
    run_f[7] = nullptr;
    run_f[8] = nullptr;
    run_f[9] = nullptr;
    run_f[10] = nullptr;
    run_f[11] = &Calculator::Put;
    run_f[12] = &Calculator::Get;
    run_f[13] = nullptr;
    run_f[14] = &Calculator::create_number;
    run_f[15] = nullptr;
    run_f[16] = &Calculator::Change_X_Y;
    run_f[17] = nullptr;
    run_f[18] = nullptr;
    run_f[19] = nullptr;
    run_f[20] = nullptr;
    run_f[21] = &Calculator::Put;
    run_f[22] = &Calculator::Get;
    run_f[23] = nullptr;
    run_f[24] = &Calculator::create_number;
    run_f[25] = nullptr;
    run_f[26] = &Calculator::Mul;
    run_f[27] = nullptr;
    run_f[28] = nullptr;
    run_f[29] = nullptr;
    run_f[30] = nullptr;
    run_f[31] = &Calculator::Put;
    run_f[32] = &Calculator::Get;
    run_f[33] = nullptr;
    run_f[34] = &Calculator::create_number;
    run_f[35] = nullptr;
    run_f[36] = &Calculator::Div;
    run_f[37] = nullptr;
    run_f[38] = &Calculator::Pow;
    run_f[39] = &Calculator::NOP;
    run_f[40] = nullptr;
    run_f[41] = &Calculator::Put;
    run_f[42] = &Calculator::Get;
    run_f[43] = &Calculator::Counterclockwise_Rotation;
    run_f[44] = &Calculator::create_number;
    run_f[45] = &Calculator::Draw_Number;
    run_f[46] = nullptr;
    run_f[47] = nullptr;
    run_f[48] = &Calculator::End_Of_Func;
    run_f[49] = &Calculator::Jmp_Greater_Equal;
    run_f[50] = nullptr;
    run_f[51] = &Calculator::Put;
    run_f[52] = &Calculator::Get;
    run_f[53] = &Calculator::Rotate_Clockwise;
    run_f[54] = &Calculator::create_number;
    run_f[55] = &Calculator::In_Sqrt;
    run_f[56] = &Calculator::Negative_Number;
    run_f[57] = nullptr;
    run_f[58] = nullptr;
    run_f[59] = &Calculator::Jmp_Equal;
    run_f[60] = nullptr;
    run_f[61] = &Calculator::Put;
    run_f[62] = &Calculator::Get;
    run_f[63] = nullptr;
    run_f[64] = &Calculator::create_number;
    run_f[65] = &Calculator::Sqrt;
    run_f[66] = nullptr;
    run_f[67] = nullptr;
    run_f[68] = &Calculator::Begin_Of_Func;
    run_f[69] = &Calculator::Jmp_Less;
    run_f[70] = nullptr;
    run_f[71] = &Calculator::Put;
    run_f[72] = &Calculator::Get;
    run_f[73] = nullptr;
    run_f[74] = &Calculator::create_number;
    run_f[75] = nullptr;
    run_f[76] = &Calculator::Cx;
    run_f[77] = nullptr;
    run_f[78] = &Calculator::End_;
    run_f[79] = &Calculator::Jmp_No_Equal;
    run_f[80] = nullptr;
    run_f[81] = nullptr;
    run_f[82] = nullptr;
    run_f[83] = nullptr;
    run_f[84] = &Calculator::create_number;
    run_f[85] = nullptr;
    run_f[86] = &Calculator::Sub;
    run_f[87] = nullptr;
    run_f[88] = nullptr;
    run_f[89] = nullptr;
    run_f[90] = nullptr;
    run_f[91] = nullptr;
    run_f[92] = nullptr;
    run_f[93] = nullptr;
    run_f[94] = &Calculator::create_number;
    run_f[95] = nullptr;
    run_f[96] = &Calculator::Add;
}

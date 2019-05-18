//
// Created by denis on 06.05.19.
//

#pragma once


#include "Libraries_Consts.h"

class tokens{
public:
    int number_comand ;
    int address_in_array ;
    tokens();
};


class Calculator {

    const char* data;

    int current_ip;

    int size_code;  // размер кодов

    vector <tokens> array_tokens;

    //int adr_return;

    //int adr_to_jmp;


    void Into_Y(int i);// много разных команд
    void Mul(int i);
    void Change_X_Y(int i);
    void Put(int i);
    void Get(int i);
    void Jmp_Greater_Equal(int adr_to_jmp);
    void Jmp_Equal(int adr_to_jmp);
    void Jmp_No_Equal(int adr_to_jmp);
    void Jmp_Less(int adr_to_jmp);
    void Sqrt(int i);
    void Div(int i);
    void Add(int i);
    void Sub(int i);
    void Pow(int i);
    void In_Sqrt(int i);
    void Cx(int i);
    void Draw_Number(int i);
    void Rotate_Clockwise(int k);
    void Counterclockwise_Rotation(int k);
    void End_(int i);
    void Negative_Number(int i);
    void Begin_Of_Func(int i);
    void End_Of_Func(int i);
    void NOP(int i);



    int Find_Right_Adr(int adr_of_command);
    void create_number(int f);
    int get_number (vector<int> number );
    bool is_it_number(int i);

public:
    explicit Calculator(const char* path);

    void Run_Calculator(); // выполняем код вызывая по указателям

    void work_with_file();

    float array_of_reg[15];

    typedef void(Calculator::*array_of_func)(int);


    array_of_func run_f[SIZE];
};


#include "Calculator.cpp"
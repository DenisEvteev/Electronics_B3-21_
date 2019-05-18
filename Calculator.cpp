//
// Created by denis on 06.05.19.
//

#include "Calculator.h"

#include "Array_Ptr_Func.cpp"

tokens::tokens():
        number_comand(0),
        address_in_array(0)
{}

void Calculator::Run_Calculator(){
    int help = 0;
    while(current_ip < size_code){
        help = (array_tokens[current_ip].number_comand / 10);
        (this->*run_f[array_tokens[current_ip].number_comand])(help);
    }
}

void Calculator::Into_Y(int i){
    array_of_reg[1] = array_of_reg[0];
    current_ip++;
}

void Calculator::Mul(int i){
    array_of_reg[0] = array_of_reg[0] * array_of_reg[1];
    current_ip++;
}


void Calculator::Put(int i){
    array_of_reg[i + BEGIN_EXTRA_REG] = array_of_reg[0];
    current_ip++;
}

void Calculator::Get(int i){
    array_of_reg[0] = array_of_reg[i + BEGIN_EXTRA_REG];
    current_ip++;
}

void Calculator::Jmp_Greater_Equal(int F){
    if(array_of_reg[0] >= 0){
        current_ip = Find_Right_Adr(array_tokens[current_ip + 1].number_comand);
    }
    else
        current_ip++;
}

void Calculator::Jmp_Equal(int F){
    if(array_of_reg[0] == 0)
        current_ip = Find_Right_Adr(array_tokens[current_ip + 1].number_comand);
    else
        current_ip++;
}

void Calculator::Jmp_No_Equal(int F){
    if(array_of_reg[0] != 0)
        current_ip = Find_Right_Adr(array_tokens[current_ip + 1].number_comand);
    else
        current_ip++;
}

void Calculator::Jmp_Less(int F){
    if(array_of_reg[0] < 0)
        current_ip = Find_Right_Adr(array_tokens[current_ip + 1].number_comand);
    else
        current_ip++;
}

int Calculator::Find_Right_Adr(int adr_of_command){
    int i = 0;
    int size = array_tokens.size();
    while(i != size){
        if(array_tokens[i].address_in_array == adr_of_command)
            return i;
        i++;
    }
}

void Calculator::Sqrt(int i){
    array_of_reg[0] = sqrt(array_of_reg[0]);
    current_ip++;
}

void Calculator::Div(int i){
    try{
        if(array_of_reg[1] == 0)
        {
            throw ERROR_N;
        }
        array_of_reg[0] = array_of_reg[0] / array_of_reg[1];
    }
    catch(char* str){
        cout << str  << endl;
    }
    current_ip++;
}

void Calculator::Change_X_Y(int i){
    float remember_x = 0;
    remember_x = array_of_reg[0];
    array_of_reg[0] = array_of_reg[1];
    array_of_reg[1] = remember_x;
    current_ip++;
}

void Calculator::Add(int i){
    array_of_reg[0] = array_of_reg[0] + array_of_reg[1];
    current_ip++;
}

void Calculator::Sub(int i){
    array_of_reg[0] = array_of_reg[0] - array_of_reg[1];
    current_ip++;
}

void Calculator::Pow(int i){
    array_of_reg[0] = pow(array_of_reg[0], array_of_reg[1]);
    current_ip++;
}

void Calculator::NOP(int i){
    cout << "The NOP has worked" << endl;
    cout << "Have a nice day" << endl;
    current_ip++;
}

void Calculator::In_Sqrt(int i){
    array_of_reg[0] = array_of_reg[0] * array_of_reg[0];
    current_ip++;
}

void Calculator::Cx(int i){
    array_of_reg[0] = 0;
    current_ip++;
}

void Calculator::Draw_Number(int i){
    array_of_reg[0] = 1 / array_of_reg[0];
    current_ip++;
}

void Calculator::Rotate_Clockwise(int k){
    int j = 6;
    float t = array_of_reg[0];
    for(int i = 1; i < j; i++){
        array_of_reg[i] = array_of_reg[i + 1];
    }
    array_of_reg[j] = t;
    current_ip++;
}

void Calculator::Counterclockwise_Rotation(int k){
    int j = 6;
    float the_first = array_of_reg[1];
    float t = 0;
    array_of_reg[1] = array_of_reg[j];
    for(int i = 2; i <= j; i++){
        t = array_of_reg[i];
        array_of_reg[i] = the_first;
        the_first = t;
    }
    current_ip++;
}

void Calculator::End_(int i){
    cout << "command c/p has worked!!!" << endl;
    cout << "The program is over" << endl;
    current_ip++;
}

void Calculator::Negative_Number(int i){
    array_of_reg[0] = -array_of_reg[0];
    current_ip++;
}

void Calculator::Begin_Of_Func(int i){
    cout << "This command mean the begin of the extra program" << endl;
    current_ip++;
}

void Calculator::End_Of_Func(int i){

    cout << "This command end the extra programm" << endl;
    current_ip++;
}

void Calculator::work_with_file() {
    FILE *file = fopen(data, "r");
    tokens help;
    int i = 0;
    int indicator = 0;
    while (fscanf(file, "%d", &(help.number_comand)) != EOF) {
        if (help.number_comand == 68 ){
            indicator = 1;
        }
        if(indicator == 0){
            help.address_in_array = NOT_CORRECT_ADR;
            array_tokens.push_back(help);
            size_code++;
        }
        if (indicator == 1){
            help.address_in_array = i;
            array_tokens.push_back(help);
            if (i % 10 == 5 || i == 5) {
                i = i + 4;
            }
            i++;
            size_code++;
        }
    }
}

bool Calculator::is_it_number(int i){
    int k = 4 ;
    while (i != k){
        if ( k > 100){
            break;
        }
        k = k+ 10;
    }
    if (i == k){
        return true;
    }
    if (i != k){
        return false;
    }
}

int Calculator::get_number (vector<int> number ){
    int size = number.size();
    int count = 0;
    int help_number = 0;
    for (int i = 0 ; i < size ; i++){
        help_number = pow(10,i);
        count = (number[size-i-1]) * help_number + count ;
    }
    return count;
}

void Calculator::create_number(int f){
    int ip = current_ip;
    vector <int> number1;
    vector <int> number2;
    int ch = 0 ;
    do {
        if(array_tokens[ip].number_comand != 46 ) {
            ch = (array_tokens[ip].number_comand / 10);
            number1.push_back(ch);
            ip++;
        }
        else{
            ip++;
            while (is_it_number(array_tokens[ip].number_comand)){
                ch = (array_tokens[ip].number_comand / 10);
                number2.push_back(ch);
                ip++;
            }
        }
    }while (is_it_number(array_tokens[ip].number_comand) || array_tokens[ip].number_comand == 46 );
    int result1 = get_number(number1);
    int result2 = get_number(number2);
    float result = result1 + (result2)/(pow(10,number2.size()));
    current_ip = ip;
    array_of_reg[0] = result;
}
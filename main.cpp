#include "Calculator.h"


int main(){

    const char* str = "/home/denis/CLionProjects/Calculator_Lec/factorial.txt";

    Calculator electornika(str);


    electornika.work_with_file();


    electornika.Run_Calculator();

    cout << electornika.array_of_reg[0] << endl;



    return 0;
}


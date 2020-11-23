#include "NameSpaceTest.h"
#include <iostream>
using namespace std;

int *Calcvalue(int a,int b)
{   

    static int result[4] = {0,};

    result[0] = a+b;
    result[1] = a-b;
    result[2] = a*b;
    result[3] = a/b;

    return result;
}

void PrintValue(int a1,int b1,int* result)
{
        cout<<"결과 : "<<endl<<"-------------------------------"<<endl;
        cout<< "a : "<<a1<<", \t" <<"b : "<<b1<<endl<<endl; 
        cout<<"a + b : "<<*result<<endl;
        cout<<"a - b : "<<*(result+1)<<endl;
        cout<<"a * b : "<<*(result+2)<<endl;
        cout<<"a / b : "<<*(result+3)<<endl<<"-------------------------------"<<endl;;

        cout<<"Continue? no: n , yes: other ";
}



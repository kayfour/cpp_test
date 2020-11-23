#include <iostream>
#include <cmath>
#include <cstdio>


using namespace std;


int StrToInt(string s)
{
    int answer = atoi(&s[0]);
    
}

int main()
{
    // cout <<"size of int : "<<sizeof(int)<<"\t";
    // cout <<"size of char : "<<sizeof(char)<<"\t";
    // cout <<"size of int8_t : "<<sizeof(int8_t)<<"\t";
    // cout <<"size of int16_t : "<<sizeof(int16_t)<<"\t";
    // cout <<"size of int32_t : "<<sizeof(int32_t)<<"\t\n";
    // cout <<"size of int64_t : "<<sizeof(int64_t)<<"\t";
    // cout <<"size of float : "<<sizeof(float)<<"\t";
    // cout <<"size of double : "<<sizeof(double)<<"\t";
    // cout <<"size of wchar_t : "<<sizeof(wchar_t)<<"\t\n";
    // return 0;

    // int result=1,first = 21;

    // result = first++;
    // // == 
    // result = first; // result = 21 
    // first = first+1; // first = 22 
    // // result = 21 , first = 22

    // result = ++first;   
    // // == 
    // first = first+1; // first = 22
    // result = first;  // result = first = 22
    cout<<StrToInt("-123")<<endl;

}

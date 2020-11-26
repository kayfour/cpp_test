#include <iostream>

using namespace std;

double getAverage(int *dat,const int len)
{
    double avg = 0;
    for(int i = 0;i<len;i++)
    {
        avg += *(dat+i);
    }
    avg /= len;
    return avg;
}


int main()
{
    const int ARR_SIZE = 5;
    int balance[ARR_SIZE]= {1000,2,3,17,50};
    double avg = 0;

    avg= getAverage(balance,ARR_SIZE);
    cout<<avg<<endl;
    cout<<*balance<<endl;
}
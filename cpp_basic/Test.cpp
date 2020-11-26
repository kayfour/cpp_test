#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int a = 0;

    cout<<("숫자값을 넣어주세요");
    cin>>a;
    int i = 0;


    while(i<a)
    {
        cout<<"hello world! \t";
        printf("%d \n",++i);
    }
   

    return 0;
}
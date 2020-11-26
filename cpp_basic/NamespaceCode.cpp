#include "NameSpaceTest.h"


using namespace std;

int main(int argc, char *argv[])
{
    int a1,b1;
    int *result;  
    char word1[5] = "word";
    char word[4] = {'w','o','r','d'};
    char c= 'y';
    cout<<word1<<" , "<<word <<", "<<(char)1<<endl;
    while(1)
    {
        // 숫자 2개 입력받음
        cout<<"input 1 : ";
        cin>>a1;
        cout<<"input 2 : ";
        cin>>b1;
        
        //입력된 숫자를 배열로 출력, 이때 출력된 변수가 static 이므로 변수를 비울 필요가 있음 
        result = Calcvalue(a1,b1);
        PrintValue(a1,b1,result);
        
        
        cin>>c;
        if( c =='n' || c =='N') 
        {
            cout<<" End the calculation! "<<endl;
            break;
        }
    }       

    return 0;
}
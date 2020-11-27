#include <iostream>
#include <stdio.h>
#include <limits>

using namespace std;

double mul_values(double a,double b)
{
    double result;
    try{
        if(b==0){throw "Division zero condition!";} // 분모가 0일경우 메세지를 출력후에 바로 catch 문으로 이동하게함.
        result = a/b;
    }
    catch(const char *msg){
        std::cout<<"Exception occur : "<<msg<<"\t";
        // 만약 분모가 0이라면 double 의 최대값을 던짐.
        return  numeric_limits<double>::max();   
               
    }
    catch(std::exception msg)
    {
        std::cout<<"caught in main(): "<<msg.what()<<endl;
        return result;   
    }

    return result;
}
int main(int argc, char **argv)
{
    double a,b;
    std::cout<<"Please insert 2 double type value"<<std::endl;

    try{
        std::cin>>a>>b;   
        double third;
        third = mul_values(a,b); 
        if(third == numeric_limits<double>::max())
        {
            while(1){ //정상적인 값이 들어올 때까지 입력반복
                std::cout<<"don't insert 0 in denominator"<<std::endl<<"Please insert 2 double type value"<<std::endl;
                a=0,b=0;
                scanf("%lf%lf",&a,&b);
                if(b!=0){third = mul_values(a,b); break;}
            }
        }
        std::cout<<"a*b is "<<third<<endl; 
    }
    catch(std::exception msg)
    {
        std::cout<<msg.what()<<endl;return -1;   
    }
    return 0;
    

}
#include <iostream>
#include <string>
using namespace std;

class test{
    // 공통으로 외부에서 접근이 가능
    public:
        void setWidth(double param_width){
            width = param_width;
        }

    // 현재 이 클래스 내에서만 접근이 가능
    private:
        double width;

    // 접근이 불가 
    protected:
        double breadth;

};
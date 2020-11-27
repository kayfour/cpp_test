
#include <iostream>
#include <string>

class Test{
    public:// 공통으로 외부에서 접근이 가능
        void setWidth(double param_width){
            width = param_width;
        }
        double setWidth(){
            return width;
        }

        Test(double len);   // 생성자 
        ~Test();            // 소멸자
    
    private:// 현재 이 클래스 내에서만 접근이 가능
        double width;

    protected:// 같은 디렉토리에 있는 것들은 접근이 가능.
        double breadth;

};

Test::Test(double len){std::cout<<"Create Test Class with assign a Test::width to "<<len<<std::endl;  width = len;}

Test::~Test(void){std::cout<<"destroy Test class"<<std::endl;}



/*
클래스를 만들때 변수를 지정해서 생성하는 것이 아니라 생성할 때 지정하기 때문에 
클래스를 생성할때 변수를 초기화 하는 것이 좋다.
*/
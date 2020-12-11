#include <iostream>

class foobar
{
private:
  int counter;

public:
// const 를 멤버함수 뒤에 사용하면 private 로 구성한 멤버 변수의 수정이 불가능하다.
  void Foo() const
  {
    int cnt = counter;
    std::cout<<cnt++<<std::endl;
  }
};



int main(int argc, char** argv)
{
    foobar *foo1 = new foobar;
    foo1->Foo();
    delete foo1;


    return 0;
}
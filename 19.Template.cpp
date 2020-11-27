#include <iostream>

using namespace std;

class Box{
    public :
        Box(double length = 2.1, double breath = 3.1, double height = 4.1){
            this->length = length;this->breath = breath;this->height = height;
        }
        double getVolume()
        {
            //std::cout<<this->length<<" "<<this->breath<<" "<<this->height<<std::endl;
            return length*breath*height;
        }
        template <typename T>   //오버라이드 함수를 새로 만드는 것이 아니라 출력되는 변수의 타입에 따라 출력 내용을 바꿔주는 새로운 타입의 선언방식이다.
                                // 여기서 선언한 T 는 데이터의 타입을 담는 틀이라는 의미이다.
        T const MAX(T a, T b)   // 다음과 같이 T 라는 변수타입을 지정할 때 출력에 따른 것이 있다.
        {
            return a>b ? a : b;
        }
    private:
        double length,breath,height;
};

int main(int argc, char** argv)
{
    Box *ptrBox = new Box[2]{{2.5,3.7},{2.7,3.6,4.7}};
    double result1= 0;
    int result2= 0;   
    
    //double 형으로 진행
    result1 = ptrBox->MAX(ptrBox->getVolume(),(ptrBox+1)->getVolume());
    //int 형으로 진행
    result2 = ptrBox->MAX((int)12,(int)13);
    std::cout<<"result 1 : "<<result1<<"   | result 2 : "<<result2<<std::endl;
    
    delete[] ptrBox;

    return 0;

}
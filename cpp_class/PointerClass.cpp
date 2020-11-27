#include <iostream>

using namespace std;

class Box{
    public :
        Box(double length = 2.1, double breath = 3.1, double height = 4.1){
            this->length = length;this->breath = breath;this->height = height;
        }
        double getVolume()
        {
            std::cout<<this->length<<" "<<this->breath<<" "<<this->height<<std::endl;
            return length*breath*height;
        }

    private:
        double length,breath,height;
};

// int main(int argc, char **argv )
// {
//     Box Box1(2.5,3.7),Box2(2.7,3.6,4.7);
//     Box *ptrBox;
//     ptrBox = &Box1;
//     std::cout<<ptrBox->getVolume()<<std::endl;

//     ptrBox = &Box2;
//     std::cout<<ptrBox->getVolume()<<std::endl;

//     return 0;
// }

int main(int argc, char ** argv)
{
    Box *ptrBox = new Box[2]{{2.5,3.7},{2.7,3.6,4.7}};
    std::cout<<ptrBox->getVolume()<<std::endl;
    std::cout<<(ptrBox+1)->getVolume()<<std::endl;
    delete ptrBox;

    return 0;

}
#include "Class.h"
using namespace std;

int main()
{
    Test test1(32.53);
    test1.setWidth(32);
    double wid = test1.setWidth();
    cout<<"variable wid == "<<wid<<endl;
    test1.~Test();
    return 0;
}
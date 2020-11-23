#include <iostream>


using namespace std;
/*

    argc -  Argument count : 커맨드 라인의 인자 수. 보통은 2개이며 하나는 인자 하나는 프로그램이름으로 되어있다.
    argv -  Argument vector : 인자의 캐릭터 배열의 수.
    
    command 창에서 현재 위치 파일 open 하기 - xdg-open ./ | 아니면 xdg-open 파일 이렇게 열 수 있음
*/
int main(int argc, char**argv)
{
    cout<<"You have entered "<<argc <<" arguments"<<endl;
    for (int i =0;i<argc;i++)
    {
        cout<<argv[i]<<endl;
        
    }
    return 0;
}

/*
    실행 결과는 아래와 같다. 이렇게 프로그램 실행시 인자를 넣을 때에는 다음과 같이 실행한다.
    이는 OS와 약속된 내용이므로 꼭 지키는 것이 좋다.

    cho@cho-B365M-DS3H:~/Documents/cpp_test$ ./15.argv_argc Command line arguments in C/C++
    You have entered 6arguments
    ./15.argv_argc
    Command
    line
    arguments
    in
    C/C++
*/
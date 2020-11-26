#include <iostream>
#include <string.h>
#include <ctime>

using namespace std;
struct Book
{
    char title[50],author[50];
    string subject;
    int book_id;

};

void printBook(struct Book *book)
{
   cout<<"Print book title : "<<book->title<<endl;
}


int main()
{
    Book book1;
    Book *temp = &book1;
    strcpy(book1.title,"Learn C+ Programming");
    book1.subject = "C++ Programing";
    strcpy(book1.author,"Chand Miyan");
    book1.book_id = 649500;  

    clock_t startTime;
    clock_t endTime;
    clock_t elapsed ;
// 측정 시간 계산 (ms단위)
   
    cout<<book1.title<<endl;
    cout<<book1.author<<endl;

// 시간 비교를 위한 코드 
    startTime = clock();
    cout<<book1.subject<<endl;
    cout<<book1.book_id<<endl;
    endTime = clock();
    elapsed = endTime - startTime;
    cout<<elapsed<<endl;
    // 포인터를 사용하면 기존과 다르게 struct 구조를 복사하는게 아닌 참조를 통해 가져오기 때문에 
    // 메모리상의 이점이 있다고한다. 포인터로 접근하는경우 아래와 같이 -> 연산자를 통해 접근해야한다.
    startTime = clock();
    cout<<&(temp->subject)<<endl;
    cout<<&(temp->book_id)<<endl;
    endTime = clock();
    elapsed = endTime - startTime;
    cout<<elapsed<<endl;
    printBook( &book1);


    
}


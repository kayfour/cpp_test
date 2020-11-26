#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main()
{
    string filename = "fstream.txt";
    ofstream outfstream(filename);

    string data;
    if(outfstream.is_open()){
        outfstream<<"This is a line."<<endl;
        cout<<"start write fstream!"<<endl;
    }

}
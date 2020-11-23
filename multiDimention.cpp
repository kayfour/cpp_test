#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void test_multi()
{
    int row,col;
    cout<< "Enter Row and Column"<<endl;
    cin>>row>>col;

    int **ptr_matrix = new int*[row];
    for (int i =0; i<row;i++)
    {   
        ptr_matrix[i] = new int[col];
        cout<<"Matrix size : "<<sizeof(ptr_matrix)<<endl;
    }
         

    for (int i =0; i<row;i++)
    {
        for (int j =0; j<col;j++)
        {
            ptr_matrix[i][j] = (i+1)*(j+1);
            cout<<"ptr_matrix["<<i<<"]["<<j<<"] = "<<ptr_matrix[i][j]<<endl;
        }
    }  
    cout<<*ptr_matrix<<endl;

    delete[] ptr_matrix;

    return ;
}

void test_vector(vector<int> numbers)
{
    vector<int> answer;  
    int temp =0;
   
    for (int i =0;i<numbers.size();i++)
    {
        for (int j=i+1;j<numbers.size();j++)
        {
            temp = numbers[i]+numbers[j];
            //cout<<temp<<"\t";
            answer.push_back(temp);
        }
        cout<<endl;
    }
    sort(answer.begin(),answer.end());
    answer.erase(unique(answer.begin(),answer.end()),answer.end());
    
    for (int i =0;i<answer.size();i++)
    {
        if ( i== answer.size()-1)
        {
            cout<<answer[i]<<endl;
            break;
        }            
        cout<<answer[i]<<" , ";

    }
 
    return;
}

int main()
{
    //test_multi();
    test_vector({2,1,3,4,11,8,9,10});

}


#include<iostream>
#include<vector>
#include<chrono>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
#include<windows.h>

using namespace std;
using namespace chrono;

void GreedySelector(vector<int>&start,vector<int>&finish,vector<string>&A){
    A.push_back("O");
    int j =1;
    for (int i = 1; i <finish.size(); i++)
    {
        if (start[i]>=finish[j])
        {
            A.push_back("O");
            j = i;
        }
        else{
            A.push_back("X");
            j=i;
        }
    }
}

void random_finish(vector<int>&finish,int n){
    srand(time(nullptr));
    for (int i = 0; i < n; i++)
    {
        if(i==0){
            finish.push_back(5);
        }
        else
        finish.push_back(rand()%(10)+finish[i-1]);
    }
}

void random_start(vector<int>&finish,vector<int>&start){
    for (int i = 0; i < finish.size(); i++)
    {
        start.push_back(finish[i]-rand()%(finish[i]/2));
    }
    
}
template<class type>
void print(vector<type>&arr){
    for (int i = 0; i <(int) arr.size(); i++)
    {
        if (i%10 == 0)
        {
            cout << setw(5) << arr[i];
        }
        else if (i%10 == 9)
        {
            cout <<' '<< setw(5) << arr[i] <<'\n';
        }
        else{
            cout <<' '<< setw(5) << arr[i];
        }
    }
}

void print_all(int length,vector<int>&start,vector<int>&finish,vector<string>&A){
    random_finish(finish,length);
    // cout<<"this is finish:\n";
    // print(finish);
    random_start(finish,start);
    // cout <<"this is start:\n";
    // print(start);
    // cout <<"this is array of conclusion:\n";
    auto start1 = system_clock::now();
    GreedySelector(start,finish,A);
    auto end = system_clock::now();
    // print(A);
    auto duration = duration_cast<microseconds>(end-start1);
    cout<<"\nThere are "<<start.size()<<" activities in array."<<"\nIt costs "<<double(duration.count())<<" us."<<'\n';
}

int main(){
    // vector<int> finish10;
    // vector<int> start10;
    // vector<string> A10;
    // print_all(10,start10,finish10,A10);
    vector<int> finish10000;
    vector<int> start10000;
    vector<string> A10000;
    print_all(10000,start10000,finish10000,A10000);
    vector<int> finish20000;
    vector<int> start20000;
    vector<string> A20000;
    print_all(20000,start20000,finish20000,A20000);
    vector<int> finish40000;
    vector<int> start40000;
    vector<string> A40000;
    print_all(40000,start40000,finish40000,A40000);
    vector<int> finish80000;
    vector<int> start80000;
    vector<string> A80000;
    print_all(80000,start80000,finish80000,A80000);
    vector<int> finish100000;
    vector<int> start100000;
    vector<string> A100000;
    print_all(100000,start100000,finish100000,A100000);
}
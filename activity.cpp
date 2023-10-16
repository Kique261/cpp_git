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
            finish.push_back(3);
        }
        else
        finish.push_back(rand()%(10)+finish[i-1]);
    }
}

void random_start(vector<int>&finish,vector<int>&start){
    for (int i = 0; i < finish.size(); i++)
    {
        start.push_back(finish[i]-rand()%(20));
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
    //cout<<"this is finish:\n";
    //print(finish);
    random_start(finish,start);
    //cout <<"this is start:\n";
    //print(start);
    //cout <<"this is array of conclusion:\n";
    auto start1 = system_clock::now();
    GreedySelector(start,finish,A);
    auto end = system_clock::now();
    //print(A);
    auto duration = duration_cast<microseconds>(end-start1);
    cout<<"\nThere are "<<start.size()<<" activities in array."<<"\nIt costs "<<double(duration.count())<<" us."<<'\n';
}

int main(){
    vector<int> finish100;
    vector<int> start100;
    vector<string> A100;
    print_all(100,start100,finish100,A100);
    vector<int> finish10000;
    vector<int> start10000;
    vector<string> A10000;
    print_all(10000,start10000,finish10000,A10000);
    vector<int> finish1000000;
    vector<int> start1000000;
    vector<string> A1000000;
    print_all(10000,start1000000,finish1000000,A1000000);
}

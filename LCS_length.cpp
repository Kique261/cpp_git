#include<iostream>
#include<vector>
#include<chrono>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
#include<windows.h>

using namespace std;
using namespace chrono;

void init_array(vector<vector<int>>&arr,int n){
    vector<int> e(n+1,0);
    for(int i=0;i<n+1;i++){
        arr.push_back(e);
    }
}


void random(vector<char>&arr,int n){
    srand(time(nullptr));
    for (int i = 0; i <n; i++)
    {
        arr.push_back((char)(rand()%(26)+97));
    }
}

void lcs_length(int m,int n,vector<char>&x, vector<char>&y,vector<vector<int>>&c,vector<vector<int>>&b){
    int i,j;
    for (i = 1; i <= m; i++)
    {
        c[i][0] = 0;
    }
    for (i = 1; i <= n; i++)
    {
        c[0][i] = 0;
    }
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (x[i] == y[j])
            {
                c[i][j] = c[i-1][j-1]+1;
                b[i][j] = 1;
            }
            else if (c[i-1][j] >= c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                b[i][j] = 2;
            }
            else{
                c[i][j] = c[i][j-1];
                b[i][j]=3;
            }
        }
    }
}

void lcs(int i,int j,vector<char>&x,vector<vector<int>>&b){
    if (i==0||j==0)
    {
        return;
    }
    if (b[i][j]==1)
    {
        lcs(i-1,j-1,x,b);
        //cout << x[i];
    }
    else if (b[i][j]==2)
    {
        lcs(i-1,j,x,b);
    }
    else{
        lcs(i,j-1,x,b);
    }
}

void print_str(vector<char>&arr){
    for (int i = 1; i < arr.size(); i++)
    {
        if (i!=arr.size()-1)
        {
            cout << arr[i];
        }
        else{
            cout << arr[i]<<'\n';
        }
        
    }
    
}

void all_in_one(int n){
    vector<char>x;
    vector<char>y;
    random(x,n);
    Sleep(2000);
    random(y,n);
    vector<vector<int>>c;
    init_array(c,n+1);
    vector<vector<int>>b;
    init_array(b,n+1);
    //cout << "This is strings:\n";
    //print_str(x);
    //print_str(y);
    auto start = system_clock::now();
    lcs_length(n,n,x,y,c,b);
    auto end = system_clock::now();
    auto duration = duration_cast<microseconds>(end-start);
    //cout << "This is Lcs: \n";
    lcs(n,n,x,b);
    cout<<"\nIt costs "<<double(duration.count())<<" us."<<'\n';
}

int main(){
    all_in_one(100);
    all_in_one(1000);
    all_in_one(10000);
}
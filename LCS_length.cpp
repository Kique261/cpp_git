#include<iostream>
#include<vector>
#include<chrono>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
#include<windows.h>

using namespace std;
using namespace chrono;

void random(char arr[100]){
    srand(time(0));
    for (int i = 0; i < 100; i++)
    {
        arr[i]=(char)(rand()%(26)+97);
    }
    Sleep(2000);
}

void lcs_length(int m,int n,char x[100], char y[100],int c[101][101],int b[101][101]){
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

void lcs(int i,int j,char x[100],int b[101][101]){
    if (i==0||j==0)
    {
        return;
    }
    if (b[i][j]==1)
    {
        lcs(i-1,j-1,x,b);
        cout << x[i];
    }
    else if (b[i][j]==2)
    {
        lcs(i-1,j,x,b);
    }
    else{
        lcs(i,j-1,x,b);
    }
}

void print_str(char arr[100]){
    for (int i = 0; i < 100; i++)
    {
        if (i!=99)
        {
            cout << arr[i];
        }
        else{
            cout << arr[i]<<'\n';
        }
        
    }
    
}

int main(){
    char x[100];
    char y[100];
    random(x);
    random(y);
    int c[101][101];
    int b[101][101];
    cout << "This is strings:\n";
    print_str(x);
    print_str(y);
    auto start = system_clock::now();
    lcs_length(100,100,x,y,c,b);
    auto end = system_clock::now();
    auto duration = duration_cast<microseconds>(end-start);
    cout << "This is Lcs: \n";
    lcs(100,100,x,b);
    cout<<"\nIt costs "<<double(duration.count())<<" us."<<'\n';
}
#include<iostream>
#include<vector>
#include<chrono>
#include<algorithm>
#include<cstdlib>
#include<iomanip>

using namespace std;
using namespace chrono;

void print_arr(int m[7][7]){
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (j%7!=6)
            {
                cout << setw(8) << m[i][j];
            }
            else{
                cout << setw(8) << m[i][j] << '\n';
            }
            
        }
        
    }
    
}

void matrix_chain(int p[7],int n,int m[7][7],int s[7][7]){
    for(int i=1;i<=n;i++){
        m[i][i]=0;
    }
    for(int r=2;r<=n;r++){
        for (int i = 1; i <= n-r+1; i++){
            int j=i+r-1;
            m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
            s[i][j]=i;
            for(int k=i+1;k<j;k++){
                int t = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if (t<m[i][j])
                {
                    m[i][j]=t;
                    s[i][j]=k;
                }
                
            }
        }
    }
}

void trace_back(int i,int j,int s[7][7]){
    if (i==j)
    {
        return;
    }
    trace_back(i,s[i][j],s);
    trace_back(s[i][j]+1,j,s);
    cout << "Multiply A " <<i<<", "<<s[i][j];
    cout <<" and A "<<(s[i][j]+1)<<", "<<j<<endl;
    
}

int main(){
    int col = 6;
    int row = 6;
    int p[7] ={30,35,15,5,10,20,25};
    int m[7][7]={0};
    int s[7][7]={0};
    auto start = system_clock::now();
    matrix_chain(p,6,m,s);
    auto end = system_clock::now();
    auto duration = duration_cast<nanoseconds>(end-start);
    print_arr(m);
    cout <<"-----------------------trace back----------------------------\n";
    trace_back(1,6,s);
    cout << "It costs "<<double(duration.count())<<" ns.";

    return 0;
}
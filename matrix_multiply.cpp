#include<iostream>
#include<vector>
#include<chrono>
#include<algorithm>
#include<cstdlib>
#include<iomanip>

using namespace std;
using namespace chrono;

void init_array(vector<vector<int>>&arr,int n){
    vector<int> e(n+1,0);
    for(int i=0;i<n+1;i++){
        arr.push_back(e);
    }
}

void random(vector<int>&p,int n){
    srand(time(0));
    for (int i = 0; i < n+1; i++)
    {
        p.push_back(rand()%20);
    }
}

void print_arr(vector<vector<int>>&m,int n){
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < n+1; j++)
        {
            if (j%(n+1)!=n)
            {
                cout << setw(8) << m[i][j];
            }
            else{
                cout << setw(8) << m[i][j] << '\n';
            }
            
        }
        
    }
    
}

void matrix_chain(vector<int>&p,int n,vector<vector<int>>&m,vector<vector<int>>&s){
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

void trace_back(int i,int j,vector<vector<int>>&s){
    if (i==j)
    {
        return;
    }
    trace_back(i,s[i][j],s);
    trace_back(s[i][j]+1,j,s);
    cout << "Multiply A " <<i<<", "<<s[i][j];
    cout <<" and A "<<(s[i][j]+1)<<", "<<j<<endl;
    
}

void print_all(vector<int>&p,vector<vector<int>>&m,vector<vector<int>>&s,int n){
    auto start = system_clock::now();
    matrix_chain(p,n,m,s);
    auto end = system_clock::now();
    auto duration = duration_cast<microseconds>(end-start);
    //print_arr(m,n);
    //cout <<"-----------------------trace back----------------------------\n";
    //trace_back(1,n,s);
    cout <<"There are "<<n<<" matrix in the chain. "<< "It costs "<<double(duration.count())<<" us.\n";
    return;
}

void all_in_one(int n){
    vector<int>p2;
    random(p2,n);
    vector<vector<int>> s2;
    init_array(s2,n);
    vector<vector<int>> m2;
    init_array(m2,n);
    print_all(p2,m2,s2,n);
}

int main(){
    vector<int>p ={30,35,15,5,10,20,25};
    vector<vector<int>> s;
    init_array(s,6);
    vector<vector<int>> m;
    init_array(m,6);
    print_all(p,m,s,6);
    all_in_one(10);
    all_in_one(100);
    all_in_one(1000);
    return 0;
}
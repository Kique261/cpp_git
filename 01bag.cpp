#include<iostream>
#include<vector>
#include<chrono>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
#include<windows.h>

using namespace std;
using namespace chrono;

template<class Typew,class Typep>
class Knap{
    friend Typep Knapsack(Typep*,Typew*,Typew,int);
    private:
    Typep Bound(int i);
    void Backtrack(int i);
    Typew c;
    int n;
    Typew* w;
    Typep* p;
    Typew cw;
    Typep cp;
    Typep bestp;
};

template<class Typew,class Typep>
void Knap<Typew, Typep>::Backtrack(int i){
    if(i>n){
        bestp = cp;
        return;
    }
    if (cw+w[i]<=c)
    {
        cw += w[i];
        cp += p[i];
        Backtrack(i+1);
        cw -= w[i];
        cp -= p[i];
    }
    if (Bound(i+1)>bestp)
    {
       Backtrack(i+1);
    }  
}



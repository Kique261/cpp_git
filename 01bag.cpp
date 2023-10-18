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


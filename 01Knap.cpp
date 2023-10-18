#include<iostream>
#include<vector>
#include<chrono>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
#include<windows.h>

using namespace std;
using namespace chrono;

struct objects
{
    int value = 0;
    int weight = 0;
};

void random_obj(vector<objects>& arr,int n){
    srand(time(nullptr));
    for (int i = 0; i < n; i++)
    {
        arr.push_back({rand()%49+1,rand()%19+1});
    }
    
}

string Backtrack(int t){
    string x;
    if(t>n){
        return x;
        x = "";
    }
}

int main(){
    vector<objects> all;
    random_obj(all,3);

}
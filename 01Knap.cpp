#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<iomanip>

using namespace std;

struct objects
{
    int value = 0;
    int weight = 0;
    int chosen = 0;
};

void random_obj(vector<objects>& arr,int n){
    srand(time(nullptr));
    for (int i = 0; i < n; i++)
    {
        arr.push_back({rand()%9+1,rand()%9+1,0});
    }
    
}

bool overweight(int t,int c,vector<objects>&all){
    int sum=0;
    for(int i=0;i<=t;i++){
        if(all[i].chosen==1){
            sum+=all[i].weight;
        }
    }
    if(sum>c){
        return false;
    }
    return true;
}

void Backtrack(int t,int c,vector<objects>&all){
    if(t>=all.size()){
        return;
    }
    else for(int i=0;i<=1;i++){
        all[i].chosen=i;
        if(overweight(t,c,all)){
            Backtrack(t+1,c,all);
        }
    }
}

void print_chosen(vector<objects>&all){
    for(int i=0;i<all.size();i++){
        cout<<all[i].weight<<all[i].chosen;
    }
}

int main(){
    vector<objects> all;
    random_obj(all,7);
    int c=100;
    Backtrack(0,c,all);
    print_chosen(all);
}
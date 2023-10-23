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

bool notoverweight(int t,int c,vector<objects>&all){
    int sum=0;
    for(int i=0;i<=t;i++){
        if(all[i].chosen==1){
            sum+=all[i].weight;
//            cout<<"sum is "<<sum<<'\n';
        }
    }
    if(sum>c){
        return false;
    }
    return true;
}

void print_chosen(vector<objects>&all){
    for(int i=0;i<all.size();i++){
        cout<<all[i].chosen;
        if(i==all.size()-1){
            cout<<'\n';
        }
    }
}

void Backtrack(int t,int c,vector<objects>&all){
    if(t>=all.size()){
        print_chosen(all);
    }
    else for(int i=0;i<=1;i++){
        all[t].chosen=i;
        if(notoverweight(t,c,all)){
            Backtrack(t+1,c,all);
        }
    }
}

int main(){
    vector<objects> all;
    random_obj(all,7);
    int c=20;
    Backtrack(0,c,all);
    print_chosen(all);
}
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
    double vpw = 0;
};

bool cmp(objects a,objects b){
    return a.vpw>b.vpw;
}

void random_obj(vector<objects>& arr,int n){
    srand(time(nullptr));
    for (int i = 0; i < n; i++)
    {
        arr.push_back({rand()%9+1,rand()%9+1,0});
        arr[i].vpw=(double)arr[i].value/(double)arr[i].weight;
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

// void print_vpm(vector<objects>&all){
//     for(int i=0;i<all.size();i++){
//         cout<<all[i].vpw<<' ';
//         if(i==all.size()-1){
//             cout<<'\n';
//         }
//     }
// }

int bestp = 0;

int cur_value(int t,vector<objects>&all){
    int sum=0;
    for (int i = 0; i <= t; i++)
    {
        if(all[i].chosen==1){
            sum += all[i].value;
        }
    }
    return sum;
}

int Bound(int t,vector<objects>&all){
    int sum = 0;
    int rest_value=0;
    for (int i = 0; i <all.size(); i++)
    {
        rest_value += all[i].value;
    }

    for (int i = 0; i <= t; i++)
    {
        if(all[i].chosen==1){
            sum += all[i].value;
        }
        rest_value -= all[i].value;
    }
    return sum+rest_value;
}

void Backtrack(int t,int c,vector<objects>&all){
    if(t>=all.size()){
        if(cur_value(t,all)>bestp){
            bestp=cur_value(t,all);
        }
        print_chosen(all);
    }
    else {
            for(int i=0;i<=1;i++){
            all[t].chosen=i;
            if(notoverweight(t,c,all) && Bound(t+1,all)>bestp){
                Backtrack(t+1,c,all);
            }
        }
    }
}



int main(){
    vector<objects> all;
    random_obj(all,7);
    sort(all.begin(),all.end(),cmp);
    // print_vpm(all);
    int c=10;
    Backtrack(0,c,all);
}
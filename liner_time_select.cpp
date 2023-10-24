#include<iostream>
#include<vector>
#include<chrono>
#include<algorithm>
#include<cstdlib>
#include<iomanip>

using namespace std;
using namespace chrono;

void random(vector<int>&arr,int n,int l,int r){
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        arr.push_back(rand()%(r-l+1)+l);
    }
    
}

int rand_k(int l,int r){
    srand(time(0));
    return rand()%(r-l+1)+l;
}

void print_arr(vector<int>&arr){
    for (int i = 0; i <(int) arr.size(); i++)
    {
        if (i%10 == 0)
        {
            cout << setw(5) << arr[i];
        }
        else if (i%10 == 9)
        {
            cout <<' '<< setw(5) << arr[i] <<'\n';
        }
        else{
            cout <<' '<< setw(5) << arr[i];
        }
    }
}

int partition1(vector<int>&arr,int l,int r,int x){
    while (l<=r)
    {
        while(arr[l]<x){
            l++;
        }
        while (arr[r]>x)
        {
            r--;
        }
        if (l <= r)
        {
            swap(arr[l],arr[r]);
            l++;
            r--;
        }  
    }
    return l;
}

int select(vector<int>&arr,int l,int r,int k){
    if (r-l<75)
    {
        sort(arr.begin(),arr.end());
        return arr[l+k-1];
    }
    for (int i = 0; i <= (r-l-4)/5; i++)
    {
        sort(arr.begin()+5*i,arr.begin()+5*i+4);
        swap(arr[l+i],arr[5*i+2]);
        int x = select(arr,l,l+(r-l-4)/5,(r-l-4)/10);
        int p = partition1(arr,l,r,x);
        int j = p-l+1;
        if(k<=j){
            return select(arr,l,p,k);
        }
        else{
            return select(arr,p+1,r,k-j);
        }
    }
    return -1;
}

void print_all(vector<int>&arr,int l,int r){
    //cout << "-----------------------"<<"random array"<<"-----------------------\n";
    //print_arr(arr);
    int target = rand_k(l,r);
    auto start = system_clock::now();
    int position = select(arr,l,r,target);
    auto end = system_clock::now();
    auto duration = duration_cast<microseconds>(end-start);
    cout << "Target is: " << target <<". Its position is: " << position <<". It costs "<<double(duration.count())<<" us."<<'\n';
    //sort(arr.begin(),arr_100.end());
    //cout << "-----------------------"<<"array after sort"<<"-------------------\n";
    //print_arr(arr);
}

int main(){
    vector<int> arr_100;
    random(arr_100,1000,0,999);
    print_all(arr_100,1,1000);
}

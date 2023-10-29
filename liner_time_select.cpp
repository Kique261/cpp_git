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

void print_all(vector<int>&arr,int n){
    random(arr,n,0,n-1);
    //cout << "-----------------------"<<"random array"<<"-----------------------\n";
    //print_arr(arr);
    int k = rand_k(0,n-1);
    auto start = system_clock::now();
    cout<<"k is:" <<k<<" Num is "<<select(arr,0,n-1,k)<<'\n';
    auto end =system_clock::now();
    auto duration = duration_cast<microseconds>(end-start);
    //sort(arr.begin(),arr.end());
    //print_arr(arr);
    cout <<"There are "<< n << " numbers in array. "<< "Liner time select costs " <<double(duration.count())<<" us.\n";
}

int main(){
    vector<int> arr_10;
    print_all(arr_10,10);
    vector<int> arr_100;
    print_all(arr_100,100);
    vector<int> arr_1000;
    print_all(arr_1000,1000);
}

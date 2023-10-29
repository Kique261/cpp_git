#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
#include<chrono>

using namespace std;
using namespace chrono;

void random(vector<int>&arr,int n,int l,int r){
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        arr.push_back(rand()%(r-l+1)+l);
    }
    
}

int partition(vector<int>&arr,int l,int r){
    int i = l;
    int j = r+1;
    int flag = arr[l];
    while(true){
        while (arr[++i]<flag&&i<r);
        while(arr[--j]>flag);
        if(i>=j){
            break;
        }
        swap(arr[i],arr[j]);
    }
    arr[l] = arr[j];
    arr[j] = flag;
    return j; 
}

void quick_sort(vector<int>&arr,int l,int r){
    if (l<r)
    {
        int q = partition(arr,l,r);
        quick_sort(arr,l,q-1);
        quick_sort(arr,q+1,r);
    }

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

void sort_and_print(vector<int>&arr){
    int length = arr.size();
    //cout << "---------------this is random arr:---------------\n";
    //print_arr(arr);
    auto start = system_clock::now();
    quick_sort(arr,0,length-1);
    auto end =system_clock::now();
    auto duration = duration_cast<microseconds>(end-start);
    //cout << "---------------this is arr after quick sort------\n";
    //print_arr(arr); 
    cout << "There is "<<length<<" nums in array.\n"<<"Quick sort costs " <<double(duration.count())<<" us.\n";
    return;
}


int main(){
    vector<int> arr_100;
    random(arr_100,100,0,99);
    sort_and_print(arr_100);
    vector<int> arr_1000;
    random(arr_1000,1000,0,999);
    sort_and_print(arr_1000);
    vector<int> arr_10000;
    random(arr_10000,10000,0,9999);
    sort_and_print(arr_10000);
    vector<int> arr_100000;
    random(arr_100000,100000,0,99999);
    sort_and_print(arr_100000);
    vector<int> arr_1000000;
    random(arr_1000000,1000000,0,999999);
    sort_and_print(arr_1000000);
}

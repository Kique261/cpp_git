#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<iomanip>

using namespace std;
int binary_search(vector<int>&nums,int target){
    int left = 0;
    int right = nums.size()-1;
    int step = 0;
    while (left <= right)
    {
        int middle = (right-left)/2+left;
        if (target == nums[middle])
        {
            step++;
            cout << "It costs "<< step << " steps." <<'\n';
            return middle;
        }
        else if (target>nums[middle])
        {
            step++;
            left=middle+1;
        }
        else if (target<nums[middle])
        {
            step++;
            right = middle-1;
        }
    }
    return -1;
}

void Init(vector<int>&arr,int n){
    for (int i = 0; i < n; i++)
    {
        arr.push_back(i+1);
    }
    
}

void time_and_search(vector<int>&arr,int target){
    
    int flag = binary_search(arr,target);
    
    cout <<"There are "<< arr.size()<<" numbers in array."<<'\n';
    cout <<"target is in:"<< flag <<'\n';
    
}

void print(vector<int>&arr){
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

int main(){
    vector<int>arr_100;
    vector<int>arr_10000;
    vector<int>arr_1000000;
    vector<int>arr_100000000;
    Init(arr_100,100);
    Init(arr_10000,10000);
    Init(arr_1000000,1000000);
    Init(arr_100000000,100000000);
    int target1 = arr_100[0];
    int target2 = arr_10000[0];
    int target3 = arr_1000000[0];
    int target4 = arr_100000000[0];
    time_and_search(arr_100,target1);
    time_and_search(arr_10000,target2);
    time_and_search(arr_1000000,target3);
    time_and_search(arr_100000000,target4);
}
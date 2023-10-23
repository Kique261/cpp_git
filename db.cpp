#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main(){
    int a[5][2]={{1,3},{2,4},{5,2},{6,1},{4,5}};
    unordered_map<vector<int>,int> path;
    for (int i = 0; i < 5; i++)
    {
        vector<int>a;
        a.push_back(a[i][0]);
        a.push_back(a[i][1]);
        path.emplace(a,a[i][1]);
    }
    auto it = path.begin(2);
    cout << it->second;
}
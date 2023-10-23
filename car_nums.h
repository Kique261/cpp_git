#include<iostream>
#include<unordered_map>
using namespace std;

class prime{
    public:
    unordered_map<int,bool> car_nums;
    void Initcar(){
    car_nums.emplace(561,true);
    car_nums.emplace(1105,1);
    car_nums.emplace(1729,1);
    car_nums.emplace(2465,1);
    car_nums.emplace(2821,1);
    car_nums.emplace(6601,1);
    car_nums.emplace(8911,1);
    car_nums.emplace(10585,1);
    car_nums.emplace(15841,1);
    car_nums.emplace(29341,1);
    car_nums.emplace(41041,1);
    car_nums.emplace(46657,1);
    car_nums.emplace(52633,1);
    car_nums.emplace(62745,1);
    car_nums.emplace(63973,1);
    car_nums.emplace(75361,1);
    car_nums.emplace(101101,1);
    car_nums.emplace(115921,1);
    car_nums.emplace(126217,1);
    car_nums.emplace(162401,1);
    car_nums.emplace(172081,1);
    car_nums.emplace(188461,1);
    car_nums.emplace(252601,1);
    car_nums.emplace(278545,1);
    car_nums.emplace(294409,1);
    car_nums.emplace(314821,1);
    car_nums.emplace(334153,1);
    car_nums.emplace(340561,1);
    car_nums.emplace(399001,1);
    car_nums.emplace(410041,1);
    car_nums.emplace(449065,1);
    car_nums.emplace(488881,1);
    car_nums.emplace(512461,1);
    }
    bool Is_carnums(int n){
        return car_nums[n];
    }
};

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
#include <cstring>
#include <cmath>
#include <queue>
#include<chrono>

using namespace std;
using namespace chrono;

struct Node
{
    int cur_value, rest_value;
    int rest_weight;
    int id;
    bool x[100];
    Node(){}

    Node(int _cur_value, int _rest_value, int _rest_weight, int _id){
        cur_value = _cur_value;
        rest_value = _rest_value;
        rest_weight = _rest_weight;
        id = _id;
        memset(x, 0, sizeof(x));
    }
};

struct objects
{
    int value;
    int weight;
};



class Knap{
    public:
        Knap(int nums,int capicity){
            n=nums;
            W=capicity;
            bestp=0;
            sum_weight=0;
            sum_value=0;
            rand_objects(n);
            for(int i=1; i<=n; i++){
                sum_weight+= All[i].weight;
                sum_value+= All[i].value;
            }
            if(sum_weight<=W){
                bestp=sum_value;
                cout<<"bestp is: "<<bestp<<endl;
                cout<<"Put all thing in the bag.";
            }
            auto start = system_clock::now();
            priority();
            auto end = system_clock::now();
            auto duration = duration_cast<microseconds>(end-start);
            // cout<<"bestp is: "<<bestp<<endl;
            // cout<<"Put these objects in the bag: ";
            // for(int i=1; i<=n; i++){
            //     if(bestx[i])
            //     cout<<i<<"  ";
            // }
            cout<<"\nThere is "<<nums<<" objects totally."<<"\nIt costs "<<double(duration.count())<<" us."<<'\n';
        }
    

    private:
        void rand_objects(int n){
            srand(time(nullptr));
            for(int i=1;i<=n;i++){
                bestx.push_back(0);
                All[i].value=rand()%29+1;
                All[i].weight=rand()%29+1;
            }
        }

        int priority(){
            int t,tcur_value,trest_value,trest_weight;
            vector<Node> jobs;
            jobs.push_back(Node(0, sum_value, W, 1)); //初始结点：空背包，rest_value=sum_value,rest_weight=W
            while(!jobs.empty()){
                Node livenode, leftchild, rightchild;//左子节点放入下一物品，右不放入
                livenode=jobs.back();
                jobs.pop_back();
                // cout<<"Id："<<livenode.id<<" cur_value: "<<livenode.cur_value<<endl;
                // cout<<"Arr X: ";
                // for(int i=1; i<=n; i++){
                //     cout<<livenode.x[i];
                // }
                // cout<<endl;
                t=livenode.id;
                if(t>n||livenode.rest_weight==0){
                    if(livenode.cur_value>=bestp){//更新最优解和最优值
                        for(int i=1; i<=n; i++)
                        {
                            bestx[i]=livenode.x[i];
                        }
                        bestp=livenode.cur_value;
                    }
                    continue;
                }
                if(livenode.cur_value+livenode.rest_value<bestp){
                    continue;
                }
                tcur_value=livenode.cur_value;
                trest_value=livenode.rest_value-All[t].value;
                trest_weight=livenode.rest_weight;
                if(trest_weight>=All[t].weight){
                    leftchild.rest_weight=trest_weight-All[t].weight;
                    leftchild.cur_value=tcur_value+All[t].value;
                    leftchild=Node(leftchild.cur_value,trest_value,leftchild.rest_weight,t+1);
                    for(int i=1;i<t;i++){
                        leftchild.x[i]=livenode.x[i];
                    }
                    leftchild.x[t]=true;
                    if(leftchild.cur_value>bestp){//比最优值大才更新
                        bestp=leftchild.cur_value;
                    }
                    jobs.push_back(leftchild);
                }
                if(tcur_value+trest_value>=bestp){
                    rightchild=Node(tcur_value,trest_value,trest_weight,t+1);
                    for(int i=1;i<t;i++){
                    rightchild.x[i]=livenode.x[i];
                    }
                    rightchild.x[t]=false;
                    jobs.push_back(rightchild);
                }
            }
            return bestp;
        }
        
    public:
        vector<bool>bestx;
        int bestp;
        int W;
        int n;
        int sum_weight;
        int sum_value;
        objects All[100];
};

int main()
{
    Knap k1(5,40);
    Knap k2(10,80);
    Knap k3(20,160);
    Knap k4(40,320);
    return 0;
}

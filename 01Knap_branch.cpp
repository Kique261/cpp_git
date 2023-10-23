#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
#include <cstring>
#include <cmath>
#include <queue>

using namespace std;

const int N = 50;
bool bestx[N];
struct Node
{
    int cur_value, rest_value;
    int rest_weight;
    int id;
    bool x[N];
    Node() {}
    Node(int _cur_value, int _rest_value, int _rest_weight, int _id){
        cur_value = _cur_value;
        rest_value = _rest_value;
        rest_weight = _rest_weight;
        id = _id;
        memset(x, 0, sizeof(x));
    }
};

bool cmp_node(Node a,Node b){
    return (a.cur_value+a.rest_value)<(b.cur_value+b.rest_value);
}

struct objects
{
    int value;
    int weight;
} objects[N];

void rand_objects(int n){
    srand(time(nullptr));
    for(int i=1;i<=n;i++){
        objects[i].value=rand()%29+1;
        objects[i].weight=rand()%19+1;
    }
}

int bestp,W,n,sum_weight,sum_value;

int bfs()
{
    int t,tcur_value,trest_value,trest_weight;
    vector<Node> jobs;
    jobs.push_back(Node(0, sum_value, W, 1)); //初始结点：空背包，rest_value=sum_value,rest_weight=W
    while(!jobs.empty())
    {
        Node livenode, lchild, rchild;//左子节点放入下一物品，右不放入
        sort(jobs.begin(),jobs.end(),cmp_node);
        livenode=jobs.back();
        jobs.pop_back();
        cout<<"Id："<<livenode.id<<" cur_value: "<<livenode.cur_value<<endl;
        cout<<"Arr X: ";
        for(int i=1; i<=n; i++)
        {
            cout<<livenode.x[i];
        }
        cout<<endl;
        t=livenode.id;
        if(t>n||livenode.rest_weight==0)
        {
            if(livenode.cur_value>=bestp)//更新最优解和最优值
            {
              for(int i=1; i<=n; i++)
              {
                bestx[i]=livenode.x[i];
              }
              bestp=livenode.cur_value;
            }
            continue;
        }
        if(livenode.cur_value+livenode.rest_value<bestp)
            continue;
        tcur_value=livenode.cur_value;
        trest_value=livenode.rest_value-objects[t].value;
        trest_weight=livenode.rest_weight;
        if(trest_weight>=objects[t].weight)
        {
            lchild.rest_weight=trest_weight-objects[t].weight;
            lchild.cur_value=tcur_value+objects[t].value;
            lchild=Node(lchild.cur_value,trest_value,lchild.rest_weight,t+1);
            for(int i=1;i<t;i++)
            {
              lchild.x[i]=livenode.x[i];
            }
            lchild.x[t]=true;
            if(lchild.cur_value>bestp)//比最优值大才更新
               bestp=lchild.cur_value;
            jobs.push_back(lchild);
        }
        if(tcur_value+trest_value>=bestp)
        {
            rchild=Node(tcur_value,trest_value,trest_weight,t+1);
            for(int i=1;i<t;i++)
            {
              rchild.x[i]=livenode.x[i];
            }
            rchild.x[t]=false;
            jobs.push_back(rchild);
        }
    }
    return bestp;
}

int main()
{
    cout << "Input the number:\n";
    cin >> n;
    cout << "Input the whole weight:\n";
    cin >> W;
    bestp=0; //最优解
    sum_weight=0;
    sum_value=0;
    rand_objects(n);
    for(int i=1; i<=n; i++)
    {
        sum_weight+= objects[i].weight;
        sum_value+= objects[i].value;
    }
    if(sum_weight<=W)
    {
        bestp=sum_value;
        cout<<"bestp is: "<<bestp<<endl;
        cout<<"Put all thing in the bag.";
        return 0;
    }
    bfs();
    cout<<"bestp is: "<<bestp<<endl;
    cout<<"Put these objects in the bag: ";
    for(int i=1; i<=n; i++)
    {
        if(bestx[i])
           cout<<i<<"  ";
    }
    return 0;
}

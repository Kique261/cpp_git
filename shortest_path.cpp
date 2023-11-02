#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<queue>
#include<chrono>

using namespace std;
using namespace chrono;

class MinNode{
    public:
        int id;
        int length;
        friend bool operator<(MinNode A,MinNode B){
            return (A.length>B.length);
        }
};

class Graph{
    public:
        void Rand_Graph(vector<vector<int>>& edges, int n_node) {
            srand(time(NULL));
            edges.assign(n_node, vector<int>(n_node, -1));
            for (int i = 1; i < n_node; i++){
                for (int j = 1; j < n_node; j++)
                {
                    if(i!=j){
                        edges[i][j]=rand()%149+1;
                    }
                } 
            }
        }

        void print_edges(vector<vector<int>>& edges) {
            int n = edges.size();
            for (int i = 1; i < n; i++) {
                for (int j = 1; j < n; j++) {
                    cout << setw(5)<< edges[i][j] << " ";
                }
                cout << endl;
            }
        }

        Graph(int n){
            n_node = n;
            v=1;
            Rand_Graph(edges,n_node);
            // cout << "生成的邻接矩阵为："<<endl;
            // print_edges(edges);
            prev.assign(n_node+1,-1);
            dist.assign(n_node,1e9);
            auto start = system_clock::now();
            short_path();
            auto end = system_clock::now();
            auto duration = duration_cast<microseconds>(end-start);
            // print_solution();
            cout<<"There are "<<n_node<<" nodes in it."<<"\nIt costs "<<double(duration.count())<<" us."<<'\n';
        }

        void short_path(){
            priority_queue<MinNode> Q;
            MinNode E ={v,0};
            dist[v]=0;
            prev[v]=0;
            while (1)
            {
                for (int i = 1; i <= n_node; i++)
                {
                    if(edges[E.id][i]>0){
                        int temp = E.length + edges[E.id][i];
                        if (temp<dist[i])
                        {
                            MinNode active = {i,temp};
                            prev[i] = E.id;
                            dist[i] = temp;
                            Q.push(active);
                        }
                    }
                }
                if(!Q.empty()){
                    E = Q.top();
                    Q.pop();
                }
                else{
                    break;
                }
            }
        }

        void print_solution(){
            for (int i = 1; i < n_node; i++)
            {
                if(i!=v){
                    int p=i;
                    vector<int> path;
                    while (prev[p]!=0)
                    {
                        path.push_back(p);
                        p=prev[p];
                    }
                    path.push_back(v);
                    reverse(path.begin(),path.end());
                    // cout << "dist:"<<endl;
                    // for (int i = 1; i < dist.size(); i++)
                    // {
                    //     cout << dist[i]<< " ";
                    // }
                    // cout << endl;
                    // cout << "prev:"<<endl;
                    // for (int i = 1; i < prev.size(); i++)
                    // {
                    //     cout << prev[i] <<" ";
                    // }
                    // cout << endl;
                    cout << v <<"->"<< i <<"的最短路径为："<<endl;
                    cout << v;
                    for (int i = 1; i < path.size(); i++)
                    {
                        cout << "->" <<path[i];
                    }
                    cout << endl;
                }
            }
            

        }

    public:
        int max_path = 50;//生成的边长上限
        int n_node;
        vector<int> prev;//前驱数组
        vector<int> dist;//距离数组
        vector<vector<int>> edges;//邻接矩阵
        int v;
        int u;
};


int main(){
    Graph G1(10);
    Graph G2(20);
    Graph G3(40);
    Graph G4(80);
    Graph G5(160);
    Graph G6(320);
}
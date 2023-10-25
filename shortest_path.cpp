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
        void Rand_Graph(vector<vector<int>>& edges, int n_node, int n_edge) {
            srand(time(NULL));
            edges.assign(n_node, vector<int>(n_node, -1));
            for (int i = 0; i < n_edge; i++) {
                int u = rand() % n_node;
                int v = rand() % n_node;
                while (u == v || (edges[u][v]>0)) {
                    v = rand() % n_node;
                }
                edges[u][v] = rand()%max_path;
                edges[v][u] = rand()%max_path;
            }
            // 遍历每个顶点，确保连通性
            vector<bool> visited(n_node, false);
            vector<int> queue;
            queue.push_back(0);
            while (!queue.empty()) {
                int u = queue.back();
                queue.pop_back();
                visited[u] = true;

                for (int v = 0; v < n_node; v++) {
                    if ((edges[u][v]>0)&& !visited[v]) {
                        queue.push_back(v);
                    }
                }
            }
            for (int u = 0; u < n_node; u++) {
                if (!visited[u]) {
                    int v = rand() % n_node;
                    while (u == v || (edges[u][v]>0)) {
                        v = rand() % n_node;
                    }
                    int p2 = rand()%max_path;
                    edges[u][v] = rand()%max_path;
                    edges[v][u] = rand()%max_path;
                }
            }
        }

        void print_edges(vector<vector<int>>& edges) {
            int n = edges.size();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << setw(5)<< edges[i][j] << " ";
                }
                cout << endl;
            }
        }

        Graph(){
            cout << "请输入顶点数和边数(随机生成边，为了保证连通实际边数会>=输入边数)："<<endl;
            cin >> n_node >> n_edge;
            // vector<int> ie1;
            // edges.push_back(ie1);
            // for (int i = 1; i <= n_node; i++)
            // {
            //     vector<int> ie2(n_node+1,1e9);
            //     edges.push_back(ie2);
            // }
            Rand_Graph(edges,n_node,n_edge);
            cout << "生成的邻接矩阵为："<<endl;
            print_edges(edges);
            prev.assign(n_node+1,-1);
            dist.assign(n_node,1e9);
            cout << "请输入起始点："<<endl;
            cin >> v >> u;
            cout << '\n';
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
            int p=u;
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
            cout << v <<"->"<< u <<"的最短路径为："<<endl;
            cout << v;
            for (int i = 1; i < path.size(); i++)
            {
                cout << "->" <<path[i];
            }
            cout << endl;
        }

    public:
        int max_path = 50;//生成的边长上限
        int n_node;
        int n_edge;
        vector<int> prev;//前驱数组
        vector<int> dist;//距离数组
        vector<vector<int>> edges;//邻接矩阵
        int v;
        int u;
};


int main(){
    Graph G;
    G.short_path();
    G.print_solution();
}
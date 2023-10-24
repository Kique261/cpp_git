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

const int MAX_PATH=50;

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
        void generateRandomGraph(vector<vector<int>>& edges, int n_node, int n_edge) {
            srand(time(NULL));
            edges.assign(n_node, vector<int>(n_node, 0));
            for (int i = 0; i < n_edge; i++) {
                int u = rand() % n_node;
                int v = rand() % n_node;
                while (u == v || (edges[u][v]>0&&edges[u][v]<100)) {
                    v = rand() % n_node;
                }
                int p1 = rand()%100;
                edges[u][v] = p1;
                edges[v][u] = p1;
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
                    if ((edges[u][v]>0&&edges[u][v]<100)&& !visited[v]) {
                        queue.push_back(v);
                    }
                }
            }
            for (int u = 0; u < n_node; u++) {
                if (!visited[u]) {
                    int v = rand() % n_node;
                    while (u == v || (edges[u][v]>0&&edges[u][v]<100)) {
                        v = rand() % n_node;
                    }
                    int p2 = rand()%100;
                    edges[u][v] = p2;
                    edges[v][u] = p2;
                }
            }
        }

        void printAdjacencyMatrix(const vector<vector<int>>& edges) {
            int n = edges.size();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << edges[i][j] << " ";
                }
                cout << endl;
            }
        }

        void Graph2(){
            cout << "请输入顶点数和边数："<<endl;
            cin >> n_node >> n_edge;
            vector<int> ie1;
            edges.push_back(ie1);
            for (int i = 1; i <= n_node; i++)
            {
                vector<int> ie2(n_node+1,1e9);
                edges.push_back(ie2);
            }
            generateRandomGraph(edges,n_node,n_edge);
            printAdjacencyMatrix(edges);
        }



    public:
        int n_node;
        int n_edge;
        vector<int> prev;//前驱数组
        vector<int> dist;//距离数组
        vector<vector<int>> edges;//邻接矩阵
        int v;
        int u;
};

Graph G;

int main(){
    G.Graph2();
}
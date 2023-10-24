#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

// 随机生成连通图的函数
void generateRandomGraph(vector<vector<int>>& edges, int n_node, int n_edge) {
    srand(time(NULL));

    // 初始化邻接矩阵为全0
    edges.assign(n_node, vector<int>(n_node, 0));

    // 随机生成边
    for (int i = 0; i < n_edge; i++) {
        int u = rand() % n_node; // 随机生成起始顶点
        int v = rand() % n_node; // 随机生成目标顶点

        // 目标顶点不能与起始顶点相同，也不能已经存在边
        while (u == v || (edges[u][v]>0&&edges[u][v]<100)) {
            v = rand() % n_node;
        }
        int p1 = rand()%100;
        edges[u][v] = p1;
        edges[v][u] = p1; // 无向图的边是双向的
    }

    // 遍历每个顶点，确保连通性
    vector<bool> visited(n_node, false);
    vector<int> queue;
    queue.push_back(0); // 从顶点0开始进行广度优先搜索

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

    // 如果有未访问的节点，添加一条边以确保连通性
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

// 打印邻接矩阵
void printAdjacencyMatrix(const vector<vector<int>>& edges) {
    int n = edges.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << edges[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n_node = 6; // 顶点个数
    int n_edge = 8; // 边个数

    vector<vector<int>> edges;
    generateRandomGraph(edges, n_node, n_edge);

    cout << "邻接矩阵：" << endl;
    printAdjacencyMatrix(edges);

    return 0;
}

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

// ���������ͨͼ�ĺ���
void generateRandomGraph(vector<vector<int>>& edges, int n_node, int n_edge) {
    srand(time(NULL));

    // ��ʼ���ڽӾ���Ϊȫ0
    edges.assign(n_node, vector<int>(n_node, 0));

    // ������ɱ�
    for (int i = 0; i < n_edge; i++) {
        int u = rand() % n_node; // ���������ʼ����
        int v = rand() % n_node; // �������Ŀ�궥��

        // Ŀ�궥�㲻������ʼ������ͬ��Ҳ�����Ѿ����ڱ�
        while (u == v || (edges[u][v]>0&&edges[u][v]<100)) {
            v = rand() % n_node;
        }
        int p1 = rand()%100;
        edges[u][v] = p1;
        edges[v][u] = p1; // ����ͼ�ı���˫���
    }

    // ����ÿ�����㣬ȷ����ͨ��
    vector<bool> visited(n_node, false);
    vector<int> queue;
    queue.push_back(0); // �Ӷ���0��ʼ���й����������

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

    // �����δ���ʵĽڵ㣬���һ������ȷ����ͨ��
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

// ��ӡ�ڽӾ���
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
    int n_node = 6; // �������
    int n_edge = 8; // �߸���

    vector<vector<int>> edges;
    generateRandomGraph(edges, n_node, n_edge);

    cout << "�ڽӾ���" << endl;
    printAdjacencyMatrix(edges);

    return 0;
}

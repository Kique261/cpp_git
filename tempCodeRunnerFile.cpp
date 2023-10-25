#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>

std::mt19937_64 mt(std::time(nullptr));

// �ж�����ͼ�Ƿ���ͨ
bool is_connected(const std::vector<std::vector<int>>& edges, int n_node) {
    std::vector<bool> visited(n_node, false);
    std::vector<int> stack;
    
    stack.push_back(0); // �ӽڵ�0��ʼ����
    visited[0] = true;

    while (!stack.empty()) {
        int node = stack.back();
        stack.pop_back();

        for (int i = 0; i < n_node; ++i) {
            if (edges[node][i] != 0 && !visited[i]) {
                visited[i] = true;
                stack.push_back(i);
            }
        }
    }

    // ����Ƿ����нڵ㶼�����ʵ�
    return std::all_of(visited.begin(), visited.end(), [](bool v) { return v; });
}

// �޸�ͼ����ͨ��
void fix_connectivity(std::vector<std::vector<int>>& edges, int n_node) {
    if (is_connected(edges, n_node)) {
        std::cout << "ͼ�Ѿ�����ͨ�ģ������޸ġ�" << std::endl;
        return;
    }

    // ������ڵ㿪ʼ��ʹ���������������DFS����ӱߣ�ֱ��ͼ��ͨΪֹ
    std::uniform_int_distribution<int> dist(0, n_node - 1);
    int start_node = dist(mt);

    std::vector<int> stack;
    std::vector<bool> visited(n_node, false);
    visited[start_node] = true;
    stack.push_back(start_node);

    while (!is_connected(edges, n_node)) {
        if (stack.empty()) {
            // �����ջΪ�գ�ѡ��һ��δ���ʵĽڵ���Ϊ�µ����
            for (int i = 0; i < n_node; ++i) {
                if (!visited[i]) {
                    start_node = i;
                    visited[i] = true;
                    stack.push_back(start_node);
                    break;
                }
            }
        } else {
            int current_node = stack.back();
            stack.pop_back();

            int target_node = dist(mt);
            if (target_node != current_node && !visited[target_node]) && edges[current_node][target_node] == 0) {
                edges[current_node][target_node] = 1;
                visited[target_node] = true;
                stack.push_back(target_node);
            }
        }
    }

    std::cout << "���޸�Ϊ��ͨͼ��" << std::endl;
}

int main() {
    int n_node = 5; // �������

    // ��ʼ���ڽӾ���ʾ��������Ը�����Ҫ���ģ�
    std::vector<std::vector<int>> edges = {
        {0, 1, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    // �޸���ͨ��
    fix_connectivity(edges, n_node);

    // ����޸�����ڽӾ���
    std::cout << "�޸����������ͨͼ�ڽӾ���" << std::endl;
    for (int i = 0; i < n_node; ++i) {
        for (int j = 0; j < n_node; ++j) {
            std::cout << edges[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>

std::mt19937_64 mt(std::time(nullptr));

// 判断有向图是否连通
bool is_connected(const std::vector<std::vector<int>>& edges, int n_node) {
    std::vector<bool> visited(n_node, false);
    std::vector<int> stack;
    
    stack.push_back(0); // 从节点0开始遍历
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

    // 检查是否所有节点都被访问到
    return std::all_of(visited.begin(), visited.end(), [](bool v) { return v; });
}

// 修复图的连通性
void fix_connectivity(std::vector<std::vector<int>>& edges, int n_node) {
    if (is_connected(edges, n_node)) {
        std::cout << "图已经是连通的，无需修改。" << std::endl;
        return;
    }

    // 从随机节点开始，使用深度优先搜索（DFS）添加边，直到图连通为止
    std::uniform_int_distribution<int> dist(0, n_node - 1);
    int start_node = dist(mt);

    std::vector<int> stack;
    std::vector<bool> visited(n_node, false);
    visited[start_node] = true;
    stack.push_back(start_node);

    while (!is_connected(edges, n_node)) {
        if (stack.empty()) {
            // 如果堆栈为空，选择一个未访问的节点作为新的起点
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

    std::cout << "已修复为连通图。" << std::endl;
}

int main() {
    int n_node = 5; // 顶点个数

    // 初始化邻接矩阵（示例，你可以根据需要更改）
    std::vector<std::vector<int>> edges = {
        {0, 1, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    // 修复连通性
    fix_connectivity(edges, n_node);

    // 输出修复后的邻接矩阵
    std::cout << "修复后的有向连通图邻接矩阵：" << std::endl;
    for (int i = 0; i < n_node; ++i) {
        for (int j = 0; j < n_node; ++j) {
            std::cout << edges[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

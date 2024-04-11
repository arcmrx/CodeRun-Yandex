#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

void DFS(int node, std::vector<std::vector<int>> &graph, std::unordered_set<int> &visited, std::vector<int> &component)
{
    visited.insert(node);
    component.push_back(node);
    for (int neighbor : graph[node])
    {
        if (visited.find(neighbor) == visited.end())
        {
            DFS(neighbor, graph, visited, component);
        }
    }
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> graph(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        std::cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    std::unordered_set<int> visited;
    std::vector<int> component;
    DFS(1, graph, visited, component);
    sort(component.begin(), component.end());
    std::cout << component.size() << "\n";
    for (int node : component)
    {
        std::cout << node << " ";
    }
    return 0;
}

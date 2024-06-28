#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

const int N = 1e5 + 5;

int n, m;
bool visited[N];
vector<unordered_set<int>> adjList;

void dfs(int u)
{
    visited[u] = true;
    cout << u << endl;
    for (int v : adjList[u])
    {
        if (!visited[v])
        {
            dfs(v);
        }
    }
}

int main()
{
    cin >> n >> m;

    // Initialize adjacency list with 'n' empty sets
    adjList.resize(n + 1);

    // Read the edges and populate the adjacency list
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].insert(v);
        adjList[v].insert(u); // For undirected graph
    }
    // Initialize visited array to false
    fill(visited, visited + n + 1, false);

    // Perform DFS traversal from each unvisited vertex
    for (int u = 1; u <= n; u++)
    {
        if (!visited[u])
        {
            dfs(u);
            // Add any additional processing for the DFS traversal here
        }
    }

    return 0;
}

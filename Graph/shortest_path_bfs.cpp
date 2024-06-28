#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj;
// vector<bool> vis;
vector<int> dist;
void BFS(int start)
{
    queue<int> q;
    q.push(start);
    // vis[start] = true;
    dist[start] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " "; // Do whatever you want with the node

        for (int neighbor : adj[node])
        {
            // if (!vis[neighbor])
            if (dist[neighbor] == -1)
            {
                q.push(neighbor);
                // vis[neighbor] = true;
                dist[neighbor] = dist[node] + 1;
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    adj.assign(n + 1, vector<int>());
    // vis.assign(n + 1, false);
    dist.assign(n + 1, -1);
    // Input graph edges
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // If it's an undirected graph
    }

    int start_node;
    cin >> start_node; // Input the starting node for BFS

    BFS(start_node);
    cout << endl;
    for (size_t i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }

    return 0;
}

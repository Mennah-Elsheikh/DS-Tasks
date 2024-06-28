// #include <iostream>
// #include <vector>
// #include <queue>
// #include <stack>
// using namespace std;
// vector<int> dist;
// int n, m;
// void BFS(int start)
// {
//     queue<int> q;
//     q.push(start);
//     dist[start] = 0;

//     while (!q.empty())
//     {
//         int node = q.front();
//         q.pop();

//         // Check conditions for valid neighbors and update distances
//         if (node * 2 <= max(2 * m, n) && dist[2 * node] == -1)
//         {
//             q.push(2 * node);
//             dist[2 * node] = dist[node] + 1;
//         }
//         if (node - 1 >= 0 && dist[node - 1] == -1)
//         {
//             q.push(node - 1);
//             dist[node - 1] = dist[node] + 1;
//         }
//     }
// }

// int main()
// {
//     cin >> n >> m;
//     dist.assign(max(2 * m + 1, n + 1), -1);
//     BFS(n);
//     cout << dist[m] << endl;
//     return 0;
// }
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int BFS(int start, int target) {
    queue<pair<int, int>> q; // Queue of pairs (node, distance)
    q.push({start, 0}); // Push the starting node with distance 0

    while (!q.empty()) {
        int node = q.front().first; // Extract the node from the front of the queue
        int distance = q.front().second; // Extract the distance from the front of the queue
        q.pop();

        // If the current node is the target, return its distance
        if (node == target) {
            return distance;
        }

        // Push valid neighbors along with their distances to the queue
        if (node * 2 <= max(2 * target, start) && distance + 1 < target) {
            q.push({2 * node, distance + 1});
        }
        if (node - 1 >= 0) {
            q.push({node - 1, distance + 1});
        }
    }

    return -1; // If target is not reachable from start
}

int main() {
    int n, m;
    cin >> n >> m;

    int shortest_distance = BFS(n, m);
    cout << shortest_distance << endl;

    return 0;
}


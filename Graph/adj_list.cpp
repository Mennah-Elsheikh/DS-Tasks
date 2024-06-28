#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Function to add an edge between two vertices
void addEdge(vector<unordered_set<int>> &adjList, int from, int to)
{
    adjList[from].insert(to);
    adjList[to].insert(from); // For undirected graph, add the edge in both directions
}

// Function to print the adjacency list
void printAdjacencyList(const vector<unordered_set<int>> &adjList)
{
    cout << "Adjacency List:" << endl;
    for (int i = 0; i < adjList.size(); ++i)
    {
        cout << "Vertex " << i << " -> ";
        for (int neighbor : adjList[i])
        {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

int main()
{
    // Example graph: 0->1, 0->2, 1->3, 2->3
    int numVertices = 4;
    vector<unordered_set<int>> adjList(numVertices);

    // Add edges to the adjacency list
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 2, 3);

    printAdjacencyList(adjList);

    return 0;
}

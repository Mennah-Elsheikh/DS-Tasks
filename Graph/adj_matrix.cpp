#include <iostream>
#include <vector>

using namespace std;

// Function to print the adjacency matrix
void printAdjacencyMatrix(const vector<vector<int>>& adjMatrix) {
    cout << "Adjacency Matrix:" << endl;
    for (const auto& row : adjMatrix) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

// Function to check if two nodes are neighbors
bool areNeighbors(const vector<vector<int>>& adjMatrix, int node1, int node2) {
    return adjMatrix[node1][node2] == 1;
}

int main() {
    int numVertices;
    cout << "Enter the number of vertices in the graph: ";
    cin >> numVertices;

    // Initialize adjacency matrix with all elements set to 0
    vector<vector<int>> adjMatrix(numVertices, vector<int>(numVertices, 0));

    int numEdges;
    cout << "Enter the number of edges in the graph: ";
    cin >> numEdges;

    cout << "Enter the edges (vertex indices separated by space):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int from, to;
        cin >> from >> to;
        adjMatrix[from][to] = 1;
        adjMatrix[to][from] = 1; // For undirected graph, set the symmetric cell
    }

    printAdjacencyMatrix(adjMatrix);

    int node1, node2;
    cout << "Enter two nodes to check if they are neighbors: ";
    cin >> node1 >> node2;

    if (areNeighbors(adjMatrix, node1, node2)) {
        cout << "Nodes " << node1 << " and " << node2 << " are neighbors." << endl;
    } else {
        cout << "Nodes " << node1 << " and " << node2 << " are not neighbors." << endl;
    }

    return 0;
}

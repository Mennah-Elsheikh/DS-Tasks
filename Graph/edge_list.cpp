#include <iostream>
#include <vector>
#include <utility>

using namespace std;

// Function to check if two nodes are neighbors in the graph
bool areNeighbors(const vector<pair<int, int>>& edgeList, int node1, int node2) {
    for (const auto& edge : edgeList) {
        if ((edge.first == node1 && edge.second == node2) || (edge.first == node2 && edge.second == node1)) {
            return true; // Found an edge connecting the two nodes
        }
    }
    return false; // No edge found between the two nodes
}

int main() {
    // Example graph: 0->1, 0->2, 1->3, 2->3
    vector<pair<int, int>> edgeList = {{0, 1}, {0, 2}, {1, 3}, {2, 3}};

    int node1, node2;
    cout << "Enter two nodes to check if they are neighbors: ";
    cin >> node1 >> node2;

    if (areNeighbors(edgeList, node1, node2)) {
        cout << "Nodes " << node1 << " and " << node2 << " are neighbors." << endl;
    } else {
        cout << "Nodes " << node1 << " and " << node2 << " are not neighbors." << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

typedef vector<unordered_set<int>> GRAPH;

void add_directed_edge(GRAPH &graph, int from, int to)
{
    graph[from].insert(to);
}

void add_undirected_edge(GRAPH &graph, int from, int to)
{
    graph[from].insert(to);
    graph[to].insert(from);
}

void print_adjaceny_matrix(GRAPH &graph)
{
    int nodes = graph.size();
    for (int from = 0; from < nodes; ++from)
    {
        cout << "Node " << from << " has neighbors: ";
        for (int to : graph[from])
            cout << to << " ";
        cout << "\n";
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    GRAPH graph(nodes); // empty sets

    for (int e = 0; e < edges; ++e)
    {
        int from, to;
        cin >> from >> to;
        add_directed_edge(graph, from, to);
    }
    print_adjaceny_matrix(graph);
    return 0;
}

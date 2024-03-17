#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge
{
    int to;
    int from;
    int cost;
};
bool compare_edges(const edge &a, const edge &b)
{
    return a.cost < b.cost;
}
typedef vector<edge> GRAPH;

void add_directed_edge(GRAPH &graph, int from, int to, int cost)
{
    graph.push_back({from, to, cost});
}

void print_adjacency_matrix(const GRAPH &graph)
{
    for (const auto &e : graph)
    {
        cout << "Edge: ( " << e.from << " " << e.to << " " << e.cost << " )" << endl;
    }
}

int main()
{
    int nodes, edges, cost;
    cin >> nodes >> edges;

    GRAPH graph;

    for (int e = 0; e < edges; ++e)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        add_directed_edge(graph, from, to, cost);
    }
    // Sort the edges based on their costs
    sort(graph.begin(), graph.end(), compare_edges);

    // Print the sorted adjacency matrix
    print_adjacency_matrix(graph);

    return 0;
}

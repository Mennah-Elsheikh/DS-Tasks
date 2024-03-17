#include <iostream>
#include <vector>
using namespace std;

// Each cell in the matrix graph[from][to] is a list of the cost
typedef vector<vector<vector<int>>> GRAPH;

void print_adjaceny_matrix(GRAPH &graph)
{
    int nodes = graph.size();
    for (int from = 0; from < nodes; ++from)
    {
        for (int to = 0; to < nodes; ++to)
        {
            for (int weight : graph[from][to])
                cout << "From " << from << " to " << to
                     << " the cost is " << weight << "\n";
        }
    }
}

void add_directed_edge(GRAPH &graph, int from,
                       int to, int cost)
{
    graph[from][to].push_back(cost);
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    GRAPH graph(nodes, vector<vector<int>>(nodes));

    for (int e = 0; e < edges; ++e)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        add_directed_edge(graph, from, to, cost);
    }
    print_adjaceny_matrix(graph);
    return 0;
}

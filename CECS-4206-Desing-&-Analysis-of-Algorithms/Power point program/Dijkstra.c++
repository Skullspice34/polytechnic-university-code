#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Define infinity as maximum integer value
#define INF numeric_limits<int>::max()

// Define a structure for representing edges in the graph
struct Edge {
    int destination; // Destination node index
    int weight;      // Weight of the edge
};

// Define a structure for representing nodes in the graph
struct Node {
    vector<Edge> edges; // List of outgoing edges
    int distance = INF; // Initially set distance to infinity
};

// Dijkstra's algorithm implementation
void dijkstra(vector<Node>& graph, int source) {
    // Set distance of source node to 0
    graph[source].distance = 0;
    // Create a priority queue to store nodes based on their distances
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // Push the source node to the priority queue
    pq.push({0, source});

    // Process nodes in the priority queue
    while (!pq.empty()) {
        // Extract the node with the minimum distance from the priority queue
        int u = pq.top().second;
        pq.pop();
        // Iterate over all outgoing edges of the current node
        for (Edge& edge : graph[u].edges) {
            int v = edge.destination, w = edge.weight;
            // Relaxation: Update the distance of the destination node if a shorter path is found
            if (graph[u].distance != INF && graph[u].distance + w < graph[v].distance) {
                graph[v].distance = graph[u].distance + w;
                // Push the updated node to the priority queue
                pq.push({graph[v].distance, v});
            }
        }
    }
}

int main() {
    // Example graph represented as an adjacency list
    vector<Node> graph = {
        {{ {1, 4}, {2, 1} }, INF},
        {{ {3, 2} }, INF},
        {{ {1, 5}, {3, 3} }, INF},
        {{}, INF}
    };

    int sourceNode = 0;
    // Call Dijkstra's algorithm to find shortest paths from the source node
    dijkstra(graph, sourceNode);

    // Output the shortest distances from the source node to all other nodes
    cout << "Shortest distances from node " << sourceNode << ":\n";
    for (size_t i = 0; i < graph.size(); ++i) {
        cout << "Node " << i << ": " << graph[i].distance << endl;
    }

    return 0;
}

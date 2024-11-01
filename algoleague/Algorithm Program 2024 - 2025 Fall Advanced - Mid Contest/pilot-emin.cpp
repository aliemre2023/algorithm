#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;
#define int long long
const int INF = numeric_limits<int>::max(); // Represents infinity

// Structure to represent an edge in the graph
struct Edge {
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

void dijkstra(const vector<vector<Edge>>& graph, int start, vector<int>& distance, const vector<int>& extras) {
    int n = graph.size();
    distance.assign(n, INF);
    distance[start] = 0; 

    //djk pq
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        if (dist > distance[u]) {
            continue;
        }

        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int w = edge.weight;

            if (distance[u] + w + extras[v] < distance[v]) {
                distance[v] = distance[u] + w + extras[v];
                pq.push({distance[v], v});
            }
        }
    }
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n + 1);  

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    vector<int> extras(n + 1); 
    for (int i = 1; i <= n; i++) {
        cin >> extras[i];
    }

    int start, end;
    cin >> start >> end;

    vector<int> distance;
    dijkstra(graph, start, distance, extras);
    if(distance[end] == 0) cout << -1;
    cout << distance[end];

    return 0;
}

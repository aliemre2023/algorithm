#include <bits/stdc++.h>
using namespace std;

void dijkstra(int src, vector<vector<pair<int, int>>>& adj, vector<int>& dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();

        if (d > dist[node]) continue;

        for (auto [neighbor, weight] : adj[node]) {
            if (dist[node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[node] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;  

    vector<vector<pair<int, int>>> adj(n + 1);  

    for (int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back({y, 1});  
        adj[y].push_back({x, 1}); 
    }

    int a, b, c;
    cin >> a >> b >> c;
    
    vector<int> distFromA(n + 1, INT_MAX);
    vector<int> distFromB(n + 1, INT_MAX);
    vector<int> distFromC(n + 1, INT_MAX);
    dijkstra(a, adj, distFromA);
    dijkstra(b, adj, distFromB);
    dijkstra(c, adj, distFromC);

    int minSum = INT_MAX;
    int resultNode = 0;
    for (int i = 1; i <= n; i++) {
        int sum = distFromA[i] + distFromB[i] + distFromC[i];
        if (sum < minSum) {
            minSum = sum;
            resultNode = i;
        } else if (sum == minSum) {
            resultNode = min(resultNode, i);
        }
    }

    cout << resultNode << "\n";

    return 0;
}

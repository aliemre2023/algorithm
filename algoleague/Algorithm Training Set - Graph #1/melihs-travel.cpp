#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, priority_queue<int, vector<int>, greater<int>>& min_heap) {
    vis[node] = 1;
    cout << node << " ";

    // Sort the adjacency list in descending order
    sort(adj[node].rbegin(), adj[node].rend());

    bool has_unvisited_neighbor = false;
    for (auto neighbor : adj[node]) {
        if (!vis[neighbor]) {
            has_unvisited_neighbor = true;
            dfs(neighbor, adj, vis, min_heap);
            break; 
        }
    }

    // If no unvisited neighbor was found, teleport to the smallest unvisited node
    if (!has_unvisited_neighbor) {
        while (!min_heap.empty() && vis[min_heap.top()]) {
            min_heap.pop(); // Remove visited nodes from heap
        }
        if (!min_heap.empty()) {
            int smallest_unvisited = min_heap.top();
            min_heap.pop();
            //cout << smallest_unvisited << " ";
            dfs(smallest_unvisited, adj, vis, min_heap);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> vis(n + 1, 0);
    vector<vector<int>> adj(n + 1); 

    // Priority queue to keep track of the smallest unvisited node
    priority_queue<int, vector<int>, greater<int>> min_heap;

    // Reading the graph and populating the adjacency list
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x); 
    }

    // Add all nodes to the priority queue
    for (int i = 1; i <= n; i++) {
        min_heap.push(i);
    }

    // Start DFS from node 1
    dfs(1, adj, vis, min_heap);

    return 0;
}

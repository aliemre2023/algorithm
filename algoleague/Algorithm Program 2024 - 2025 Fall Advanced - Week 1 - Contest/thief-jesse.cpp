#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define int long long

// Union-Find data structure
class UnionFind {
public:
    vector<int> parent, size;
    
    UnionFind(int n) {
        parent.resize(n+1);
        size.resize(n+1, 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int find(int u) {
        if (parent[u] != u) parent[u] = find(parent[u]);
        return parent[u];
    }

    void unite(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);
        if (root_u != root_v) {
            if (size[root_u] < size[root_v]) swap(root_u, root_v);
            parent[root_v] = root_u;
            size[root_u] += size[root_v];
        }
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, C;
    cin >> n >> m >> C; 

    vector<int> weights(n+1, 0);
    vector<int> values(n+1, 0);
    
    for (int i = 1; i <= n; i++) {
        cin >> weights[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> values[i];
    }

    UnionFind uf(n);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        uf.unite(x, y);
    }

    vector<vector<int>> groups(n+1);
    for (int i = 1; i <= n; i++) {
        int root = uf.find(i);
        groups[root].push_back(i);
    }

    vector<int> dp(C+1, 0);

    for (int root = 1; root <= n; root++) {
        if (!groups[root].empty()) {
            vector<pair<int, int>> items;  // (total_weight, total_value)
            items.push_back({0, 0});  

            for (int item : groups[root]) {
                items.push_back({weights[item], values[item]});
            }

            vector<int> new_dp = dp; 
            for (auto& item : items) {
                int weight = item.first;
                int value = item.second;
                for (int j = C; j >= weight; j--) {
                    new_dp[j] = max(new_dp[j], dp[j - weight] + value);
                }
            }
            dp = new_dp;
        }
    }

    int result = *max_element(dp.begin(), dp.end());
    cout << result << endl;

    return 0;
}

//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int dfs(int i, int j, vector<vector<int>>& adj, vector<vector<int>>& vis, int& currTotal){
    int n = adj.size();
    int m = adj[0].size();

    vis[i][j] = 1;
    currTotal += adj[i][j];

    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for(auto d : directions) {
        int ni = i + d.first;
        int nj = j + d.second;

        if(ni >= 0 && ni < n && nj >= 0 && nj < m && adj[ni][nj] != 0 && !vis[ni][nj]){
            dfs(ni, nj, adj, vis, currTotal); 
        }
    }
    return currTotal;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int c, r; cin >> c >> r;
    vector<vector<int>> grid(r, vector<int>(c, 0));
    vector<vector<int>> vis(r, vector<int>(c, 0));
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            int x; cin >> x;
            grid[i][j] = x;
        }
    }

    int maxi = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(!vis[i][j] && grid[i][j] != 0){
                int currTotal = 0;
                int curr = dfs(i, j, grid, vis, currTotal);
                maxi = max(maxi, curr);
            }
        }
    }
    cout << maxi;
	return 0;
}
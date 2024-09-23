//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int shortestPath(vector<vector<int>>& grid, pair<int,int> src, pair<int,int> dest, vector<vector<int>>& vis){
    if(src.first==dest.first && src.second==dest.second) return 0;

    queue<pair<int, pair<int, int>>> q;

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    dist[src.first][src.second] = 0;

    vector<pair<int, int>> directions = {{-1, 2}, {-1, -2}, {1, 2}, {1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
    
    q.push({0, {src.first, src.second}});

    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int dis = it.first;
        int r = it.second.first;
        int c = it.second.second;

        for(auto d : directions){
            int nr = r + d.first;
            int nc = c + d.second;

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 0 && dis + 1 < dist[nr][nc]){
                if(!vis[nr][nc]){
                    dist[nr][nc] = 1 + dis;
                    if(nr == dest.first && nc == dest.second){
                        return dis + 1;
                    }
                    q.push({1 + dis, {nr, nc}});
                }
            }
        }
    }
    return -1;
}

int main() {
// write your code here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<vector<int>> grid(n, vector<int>(n,0));
    vector<vector<int>> vis(n, vector<int>(n,0));
    pair<int,int> src, dest;
    int x, y;
    cin >> x >> y;
    x--; y--;
    src = {x, y};
    cin >> x >> y;
    x--; y--;
    dest = {x, y};
    
    int res = shortestPath(grid, src, dest, vis);
    cout << res;
    
	return 0;
}

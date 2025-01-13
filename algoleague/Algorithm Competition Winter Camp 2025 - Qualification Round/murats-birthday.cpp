#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

//const
const vector<pair<int,int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

inline void bfsTimeGrid(const vector<vector<int>>& grid, vector<vector<int>>& time_grid, const int start_x, const int start_y) {
    const int n = grid.size();
    fill(time_grid.begin(), time_grid.end(), vector<int>(n, LLONG_MAX)); //
    
    if(grid[start_x][start_y] == '#') return;
    
    queue<pair<int,int>> q;
    q.push({start_x, start_y});
    time_grid[start_x][start_y] = 0;
    
    while(!q.empty()) {
        const int x = q.front().first;
        const int y = q.front().second;
        const int curr_time = time_grid[x][y];
        q.pop();
        
        for(const auto& d : directions) {
            const int nx = x + d.first;
            const int ny = y + d.second;
            
            // boundary
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(grid[nx][ny] == '#' || time_grid[nx][ny] != LLONG_MAX) continue;
            
            time_grid[nx][ny] = curr_time + 1;
            q.push({nx, ny});
        }
    }
}

int32_t main() {
    fastio;
    
    int n, k; 
    cin >> n >> k;
    
    vector<vector<int>> grid(n, vector<int>(n));
    vector<vector<int>> time_grid(n, vector<int>(n));
    char x;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> x;
            grid[i][j] = x;
        }
    }
    
    vector<vector<vector<int>>> bfs_results(k, vector<vector<int>>(n, vector<int>(n)));
    
    for(int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        bfsTimeGrid(grid, bfs_results[i], x, y);
    }
    
    int l; 
    cin >> l;
    vector<pair<int,int>> times;
    times.reserve(k); 
    
    while(l--) {
        int x, y;
        cin >> x >> y;
        
        if(grid[x][y] == '#') {
            cout << "-1 -1\n";
            continue;
        }
        
        times.clear(); // reuse v
        
        int min_box = -1, max_box = -1;
        int min_time = LLONG_MAX, max_time = -1;
        
        // nlogn->n sort
        for(int j = 0; j < k; j++) {
            int time = bfs_results[j][x][y];
            if(time != LLONG_MAX) {
                if(time < min_time) {
                    min_time = time;
                    min_box = j + 1;
                }
                if(time > max_time) {
                    max_time = time;
                    max_box = j + 1;
                }
            }
        }
        
        if(min_box != -1) {
            cout << min_box << " " << max_box << "\n";
        } else {
            cout << "-1 -1\n";
        }
    }
    
    return 0;
}
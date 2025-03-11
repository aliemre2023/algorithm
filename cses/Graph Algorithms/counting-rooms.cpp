#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define int long long

int bfs(vector<vector<char>> grid){
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    int room_count = 0;
    vector<pair<int,int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    queue<pair<int,int>> q;

    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(grid[i][j] != '.' || visited[i][j]){
                continue;
            }
            q.push({i, j});
            visited[i][j] = true;
            room_count++;

            while(!q.empty()){
                pair<int,int> node = q.front();
                q.pop();
                int node_i = node.first;
                int node_j = node.second;

                for(auto direction: directions){
                    int new_i = node_i + direction.first;
                    int new_j = node_j + direction.second;
                    if(new_i >= 0 && new_i < grid.size() && new_j >= 0 && new_j < grid[0].size() && grid[new_i][new_j] == '.' && !visited[new_i][new_j]) {
                        visited[new_i][new_j] = true;
                        q.push({new_i, new_j});
                     }
                }
            }
        }    
    }

    return room_count;

}

int32_t main(){
    int n, m; cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m, '#'));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char x; cin >> x;
            grid[i][j] = x;
        }
    }

    int room_count = bfs(grid);
    cout << room_count;


}
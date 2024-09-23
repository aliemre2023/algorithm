//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast h
#include <bits/stdc++.h>

using namespace std;

void dfs(int currentVertex, vector<vector<int>>& adjL, vector<bool>& visited) {
    visited[currentVertex] = true;

    for (int neighbor : adjL[currentVertex]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adjL, visited);
        }
    }
}

int cities(vector<vector<int>>& adjL) {
    int nodes = adjL.size();
    vector<bool> visited(nodes, false);
    int cityNum = 0;

    for (int i = 0; i < nodes; ++i) {
        if (!visited[i]) {
            cityNum++;
            dfs(i, adjL, visited);
        }
    }

    return cityNum;
}


int main() {
// write your code here

    int nodes; cin >> nodes;
    int edges; cin >> edges;
    
    
    
    vector<vector<int> > adjL(nodes, vector<int>(1, 0));
    for(int i = 0; i < edges; i++){
        
        int x, y; cin >> x >> y;
        
        adjL[x-1].push_back(y-1);
        adjL[y-1].push_back(x-1);
        
    }
    
    int city = cities(adjL);
    cout << city;
    
    
    
    
    
	return 0;
}

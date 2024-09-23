//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>
#define int long long
using namespace std;

int shortestPath(int n, int m, vector<vector<pair<int,int>>>& adj, int start, int end){


    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(n, 1e9); 


    dist[start] = 0;
    pq.push({0, start}); 

    while(!pq.empty()){
        auto it = pq.top();
        int node = it.second;
        int dis = it.first;
        pq.pop();

        for(auto it : adj[node]){
            int adjNode = it.first;
            int edW = it.second;
            if(dis + edW < dist[adjNode]){
                dist[adjNode] = dis + edW;
                pq.push({dis + edW, adjNode});

            }
        }
    }
    if(dist[end] == 1e9){ 
        return -1;
    }

    // total distance 
    return dist[end];

    

}

int32_t main() {
// write your code here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    int h, f, e; cin >> h >> f >> e; 
    h--; f--; e--;
    
    vector<vector<pair<int,int>>> adj(n); 
    for(int i = 0; i < m; i++){
        int x, y, d; cin >> x >> y >> d;
        x--; y--;
        adj[x].push_back({y,d});
        adj[y].push_back({x,d});
    }
    
    int a = shortestPath(n, m, adj, h, f);
    int b = shortestPath(n, m, adj, h, e);
    int c = shortestPath(n, m, adj, f, e);
   
    cout << min(a+c,b+c);
    
	return 0;
}
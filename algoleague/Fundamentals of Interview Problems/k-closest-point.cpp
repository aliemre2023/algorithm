//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
// write your code here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k; cin >> n >> k;
    vector<pair<int, pair<int, int>>> points;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        points.push_back({i, {a, b}});
    }
    int x, y; cin >> x >> y;
    
    vector<pair<int,int>> dists;
    for(int i = 0; i < n; i++){
        int cx = points[i].second.first;
        int cy = points[i].second.second;
        int distSquared = (x - cx) * (x - cx) + (y - cy) * (y - cy); 
        dists.push_back({distSquared, i});
    }
    sort(dists.begin(), dists.end());
    
    for(int i = 0; i < k; i++){
        cout << points[dists[i].second].second.first << " " << points[dists[i].second].second.second << "\n";
    }
	return 0;
}

//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
// write your code here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    
    unordered_map<int,set<int>> mp(n);
    
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        if(x == y) continue;
        mp[x].insert(y);
    }
    
    for(int i = 1; i < n+1; i++){
        if(mp[i].size() != n-1){
            cout << "No" << "\n";
            return 0;
        }
    }
    cout << "Yes" << "\n";
	return 0;
}

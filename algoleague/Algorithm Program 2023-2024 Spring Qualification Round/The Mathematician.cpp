//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i].first = i+1;
        cin >> arr[i].second;
    }
    
    int res = 0;
    
    map<int,int> mp;
    for(auto x: arr){
        mp[x.second - (x.first * m)]++;
    }
    for(auto x: mp){
        res += (x.second*(x.second-1)) / 2;
    }
    
    cout << res;

    return 0;
}

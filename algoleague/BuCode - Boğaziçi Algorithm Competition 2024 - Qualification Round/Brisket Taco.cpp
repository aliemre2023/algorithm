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
        cin >> arr[i].first >> arr[i].second;
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

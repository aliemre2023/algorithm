#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    
    vector<pair<int,int>> arr;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        arr.push_back({a, b});
    }
    int x, y; cin >> x >> y;

    vector<pair<int, int>> result;
    bool merged = false;

    for(int i = 0; i < n; i++) {
        if (arr[i].second < x) {
            result.push_back(arr[i]);
        } else if (arr[i].first > y) {
            if (!merged) {
                result.push_back({x, y});
                merged = true;
            }
            result.push_back(arr[i]);
        } else {
            x = min(x, arr[i].first);
            y = max(y, arr[i].second);
        }
    }

    if (!merged) {
        result.push_back({x, y});
    }

    for(const auto& interval : result) {
        cout << interval.first << " " << interval.second << "\n";
    }

    return 0;
}

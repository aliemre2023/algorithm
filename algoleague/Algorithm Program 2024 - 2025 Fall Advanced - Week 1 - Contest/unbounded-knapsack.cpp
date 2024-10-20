#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    int n; cin >> n;
    int m; cin >> m;
    
    vector<int> arr;
    int tot = 0;
    
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        arr.push_back(x);
    }

    vector<int> dp(m+1, 0);
    dp[0] = 1;
    
    for(int i = 0; i < n; i++) {
        for(int j = arr[i]; j <= m; j++) {
            if(dp[j - arr[i]]) {
                dp[j] = 1; 
            }
        }
    }
    
    for(int i = m; i >= 0; i--){
        if(dp[i]){
            cout << i;
            break;
        }
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    int n; 
    cin >> n;
    
    vector<int> w(n);
    int tot = 0;
    
    for(int i = 0; i < n; i++) {
        cin >> w[i];
        tot += w[i];
    }

    vector<int> dp(2 * tot + 1, 0);
    dp[tot] = 1;
    
    for(int i = 0; i < n; i++) {
        vector<int> new_dp(dp);
        for(int j = 0; j <= 2 * tot; j++) {
            if(dp[j]) {  
                if(j + w[i] <= 2 * tot) {
                    new_dp[j + w[i]] = 1;
                }
                if(j - w[i] >= 0) {
                    new_dp[j - w[i]] = 1;
                }
            }
        }
        dp = new_dp;
    }
    
    int diff = 0;
    for(int i = tot + 1; i <= 2 * tot; i++) {
        if(dp[i] != 0) {
            diff++;
        }
    }
    
    cout << diff << endl;
    
    return 0;
}

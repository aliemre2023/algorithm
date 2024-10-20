#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = 1007;
int32_t main() {
    int n; cin >> n;
    
    vector<vector<int>> dp(2,vector<int>(n,0));
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[0][1] = 1;
    dp[1][1] = 2;
    
    for(int i = 2; i < n; i++){
        dp[0][i] = dp[1][i-1];
        dp[1][i] = (dp[0][i-1] + dp[0][i-2]) % MOD;
    }
    cout << (dp[0][n-1] + dp[1][n-1]) % MOD;
    
    
    return 0;
}

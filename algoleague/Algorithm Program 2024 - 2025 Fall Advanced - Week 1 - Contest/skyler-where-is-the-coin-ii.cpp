#include <bits/stdc++.h>
using namespace std;
int MOD = 1000000007;

int32_t main() {
    int n, m; 
    cin >> n >> m;
    
    vector<int> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    
    vector<long long> dp(m+1, 0);
    dp[0] = 1;
    
    for(int j = 1; j <= m; j++){
        for(int i = 0; i < n; i++){
            int x = coins[i];
            if(j - x >= 0){
                dp[j] = (dp[j - x] + dp[j]);
                dp[j] %= MOD;
            }
        }
    }
    
    cout << dp[m] % MOD << endl;
    return 0;
}

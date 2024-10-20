//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;
int MOD = 1e9+7;

int main() {
// write your code here
    int n, m; cin >> n >> m;
    
    vector<int> dp(m+1);
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        for(int j = 0; j < m+1;j++){
            if(dp[j] != 0){
                if(j+x < dp.size()){
                    dp[j+x] = (dp[j+x]  + dp[j]) % MOD;
                }
            }
        }
    }
    
    cout << dp[m] % MOD;
	return 0;
}

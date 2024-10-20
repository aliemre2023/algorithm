//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main() {
// write your code here
    int n, k; cin >> n >> k;
    
    vector<int> profits(n);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        profits[i] = x;
    }
    vector<int> weights(n);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        weights[i] = x;
    }
    
    vector<int> dp(k+1, 0);

    for(int i = 0; i < n; i++){
        int profit = profits[i];
        int weight = weights[i];
        
        for(int j = k; j >= weight; j--) {
            dp[j] = max(dp[j], dp[j - weight] + profit);
        }
    }
    
    cout << dp[k];
    
	return 0;
}

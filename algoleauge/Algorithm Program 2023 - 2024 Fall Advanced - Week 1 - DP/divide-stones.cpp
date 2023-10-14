// Question Link = https://algoleague.com/contest/algorithm-program-2023-2024-fall-advanced-week-1-dp/problem/divide-stones/

//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
// write your code here
    int n; cin >> n;
    int sum = 0;
    vector<int> stones;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        sum += x;
        stones.push_back(x);
    }
    if (sum % 2 != 0) {
        cout << "false"; 
        return 0;
    }
    
    int targetSum = sum / 2;
    vector<vector<bool>> dp(n + 1, vector<bool>(targetSum + 1, false));

    dp[0][0] = true;
    
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= sum/2; j++){
            if(j < stones[i-1]) dp[i][j] = dp[i-1][j];
            else{
                dp[i][j] = dp[i-1][j] || dp[i-1][j - stones[i-1]];
            }
        }
    }
    if(dp[n][targetSum]) cout << "true";
    else cout << "false";
    
	return 0;
}

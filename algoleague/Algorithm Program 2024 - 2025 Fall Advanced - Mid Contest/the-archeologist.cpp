#include <iostream>
#include <vector>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;  
    cin >> n >> k;

    vector<int> profits(n);
    vector<int> weights(n);
    vector<int> quantities(n);

    for(int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        profits[i] = y;   
        weights[i] = x;    
        quantities[i] = z; 
    }


    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 1; i <= n; i++) { 
        int profit = profits[i - 1];
        int weight = weights[i - 1]; 
        int quantity = quantities[i - 1]; 

        for (int j = 0; j <= k; j++) { 
            dp[i][j] = dp[i - 1][j];
            // _ n dp
            for (int c = 1; c <= quantity; c++) {
                if (j >= c * weight) { // c items to curr idx
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - c * weight]+(c*profit));
                } 
                else {
                    break;
                }
            }
        }
    }

    cout << dp[n][k] << endl;

    return 0;
}

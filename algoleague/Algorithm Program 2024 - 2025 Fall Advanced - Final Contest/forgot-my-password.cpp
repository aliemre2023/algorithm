#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
#define int long long

class Solution {
public:
    int numDistinctSubsequences(string s) {
        int n = s.size();
        vector<long long> dp(n + 1, 1); // dp[i] , s[0..i-1]
        unordered_map<char, int> last_occurrence; 

        for (int i = 1; i <= n; ++i) {
            dp[i] = (2 * dp[i - 1]) % MOD;
            char current_char = s[i - 1];
            if (last_occurrence.find(current_char) != 
                    last_occurrence.end()) {
                dp[i] = (dp[i] - dp[last_occurrence[current_char] - 1] + MOD) % MOD;
            }
            last_occurrence[current_char] = i;
        }

        return (dp[n] - 1 + MOD) % MOD; 
    }
};

int32_t main() {
    Solution sol;
    int n; cin >> n;
    string str;
    cin >> str;

    int result = sol.numDistinctSubsequences(str);
    set<string> setstr;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            setstr.insert(str.substr(i, j - i + 1));
        }
    }

    cout << result-setstr.size() << "\n";

    return 0;
}
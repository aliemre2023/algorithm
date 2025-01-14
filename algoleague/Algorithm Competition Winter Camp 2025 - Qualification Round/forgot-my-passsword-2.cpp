// https://www.geeksforgeeks.org/count-distinct-substrings-string-using-suffix-array/
// https://leetcode.com/problems/distinct-subsequences-ii/description/

//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
#define int long long

using namespace std;


struct suffix {
    int index;  // To store original index
    int rank[2]; // To store ranks and next rank pair
};

// A comparison function used by sort() to compare two suffixes.
int cmp(struct suffix a, struct suffix b) {
    return (a.rank[0] == b.rank[0]) ?
           (a.rank[1] < b.rank[1] ? 1 : 0) :
           (a.rank[0] < b.rank[0] ? 1 : 0);
}

// This function builds and returns the suffix array
vector<int> buildSuffixArray(string txt, int n) {
    struct suffix suffixes[n];

    // Initialize the suffixes array
    for (int i = 0; i < n; i++) {
        suffixes[i].index = i;
        suffixes[i].rank[0] = txt[i] - 'a';
        suffixes[i].rank[1] = ((i + 1) < n) ? (txt[i + 1] - 'a') : -1;
    }

    // Sort the suffixes based on the first two characters (initial rank and next rank)
    sort(suffixes, suffixes + n, cmp);

    int ind[n];
    for (int k = 4; k < 2 * n; k = k * 2) {
        int rank = 0;
        int prev_rank = suffixes[0].rank[0];
        suffixes[0].rank[0] = rank;
        ind[suffixes[0].index] = 0;

        for (int i = 1; i < n; i++) {
            if (suffixes[i].rank[0] == prev_rank && suffixes[i].rank[1] == suffixes[i - 1].rank[1]) {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = rank;
            } else {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = ++rank;
            }
            ind[suffixes[i].index] = i;
        }

        for (int i = 0; i < n; i++) {
            int nextindex = suffixes[i].index + k / 2;
            suffixes[i].rank[1] = (nextindex < n) ? suffixes[ind[nextindex]].rank[0] : -1;
        }

        sort(suffixes, suffixes + n, cmp);
    }

    vector<int> suffixArr;
    for (int i = 0; i < n; i++) {
        suffixArr.push_back(suffixes[i].index);
    }

    return suffixArr;
}

// Function to construct and return LCP array
vector<int> kasai(string txt, vector<int> suffixArr) {
    int n = suffixArr.size();
    vector<int> lcp(n, 0);
    vector<int> invSuff(n, 0);

    for (int i = 0; i < n; i++) {
        invSuff[suffixArr[i]] = i;
    }

    int k = 0;
    for (int i = 0; i < n; i++) {
        if (invSuff[i] == n - 1) {
            k = 0;
            continue;
        }

        int j = suffixArr[invSuff[i] + 1];
        while (i + k < n && j + k < n && txt[i + k] == txt[j + k]) {
            k++;
        }

        lcp[invSuff[i]] = k;
        if (k > 0) {
            k--;
        }
    }

    return lcp;
}

// Method to return count of total distinct substrings
int countDistinctSubstring(string txt) {
    int n = txt.length();
    vector<int> suffixArr = buildSuffixArray(txt, n);
    vector<int> lcp = kasai(txt, suffixArr);

    int result = n - suffixArr[0]; // Count substrings of the first suffix
    for (int i = 1; i < lcp.size(); i++) {
        result += (((n - suffixArr[i]) - lcp[i - 1]) + MOD ) % MOD;
        result = (result + MOD) % MOD;
    }

    return result;
}
  

class Solution {
public:
    
    int numDistinctSubsequences(string s) {
        int n = s.size();
        vector<long long> dp(n + 1, 1); // dp[i] , s[0..i-1]
        unordered_map<char, int> last_occurrence; 

        for (int i = 1; i <= n; ++i) {
            dp[i] = (2 * dp[i - 1]) % MOD;
            char current_char = s[i - 1];
            if (last_occurrence.find(current_char) != last_occurrence.end()) {
                dp[i] = (dp[i] - dp[last_occurrence[current_char] - 1] + MOD) % MOD;
            }
            last_occurrence[current_char] = i;
        }

        return (dp[n] - 1 + MOD) % MOD; 
    }
    int countSub(string s) {
        map<char, int> mp;
    
        int n = s.size();
        int allCount = 0, levelCount = 0;
    
        for (int i = 0; i < n; i++) {
            char c = s[i];
    
            if (i == 0) {
                allCount = levelCount = 1;
                mp[c] = 1; // Initialize the map with the first character
                continue;
            }
    
            levelCount = allCount + 1;
    
            if (mp.find(c) == mp.end()) {
                allCount += levelCount;
            } else {
                allCount += levelCount - mp[c];
            }
            mp[c] = levelCount; // Update the count for the current character
        }
    
        return allCount;
    }
    
    int distinctSubseqII(string s) {
        const int N = s.length();
        const int MOD = 1e9 + 7;
        
        vector<int> dp(N+1);
        dp[0] = 1;
        vector<int> last(26, -1);
        
        for(int i = 0; i < N; i++){
            int x = s[i] - 'a';
            dp[i+1] = dp[i] * 2 % MOD;
            if(last[x] >= 0) // if this is the first occurence of ch
                dp[i+1] -= dp[last[x]];
            dp[i+1] %= MOD;
            last[x] = i;
        }
        dp[N]--;
        if(dp[N] < 0) dp[N] += MOD;
        return dp[N];
    }
};

int32_t main() {
    Solution sol;
    int n; cin >> n;
    string str;
    cin >> str;

    int result = sol.numDistinctSubsequences(str); // T: N // S: N
    int subsC = countDistinctSubstring(str);  // W// T: nlogn // S: N

    cout << ((result-subsC) + MOD) % MOD<< "\n";

    return 0;
}

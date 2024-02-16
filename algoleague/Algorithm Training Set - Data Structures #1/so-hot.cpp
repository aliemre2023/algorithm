//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 1e9 + 7;

int power(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}
int32_t main() {
// write your code here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;

    int hot = 0;

    map<int,int> mp;
    int x; cin >>x;
    mp[x] = 1;
    for(int i = 2; i < n+1; i++){
        cin >> x;

        auto it = mp.lower_bound(x);
        if (it != mp.begin()) {
            --it;
            int addval = power(x - it->first, i - it->second, MOD);
            hot = (hot + addval) % MOD;
        }
        mp[x] = i;

    }

    cout << hot % MOD;

	return 0;
}

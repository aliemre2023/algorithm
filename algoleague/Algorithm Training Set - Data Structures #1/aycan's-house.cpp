// Question Link = https://algoleague.com/contest/algorithm-program-2023-2024-fall-advanced-qualification-round/problem/aycans-house/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main() {
    ll n;
    cin >> n;
    
    ll res = 0;
    ll sum = 0;
    unordered_map<ll, ll> prefixSumCounts;
    prefixSumCounts[0] = 1;

    for (ll i = 0; i < n; i++) {
        ll a; cin >> a;
        sum += a;


        if (prefixSumCounts.find(sum) != prefixSumCounts.end()) {
            res += prefixSumCounts[sum];
        }

        prefixSumCounts[sum]++;
    }

    cout << res;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    
    vector<ll> divisors;
    for(ll i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            if(i != n/i){
                divisors.push_back(i);
                divisors.push_back(n/i);
            }
            else{
                divisors.push_back(i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());
    
    vector<pair<ll, ll>> arr;
    arr.push_back({1, 1});
    for (ll i = 0; i < divisors.size(); i++) {
        ll will_sec = 0;
        for (ll j = 0; j <= arr.size()-1; j++) {
            if (divisors[i] % arr[j].first == 0) {
                will_sec += arr[j].second;
            }
        }
        arr.push_back({divisors[i], will_sec});
    }
    
    ll res = 1;
    for (ll i = 0; i < divisors.size(); i++) {
        ll divisor = divisors[i];
        for (ll j = 0; j < arr.size(); j++) {
            if (arr[j].first == divisor) {
                res += arr[j].second;
                break; 
            }
        }
    }
    cout << res;
    return 0;
}

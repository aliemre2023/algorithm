#include <bits/stdc++.h>

using namespace std;
#define room 1299827
#define MOD 1000000007
#define int long long
vector<int> fact(room), inv_fact(room);

long long mod_inverse(long long a, long long m) {
    long long m0 = m, y = 0, x = 1;
    if (m == 1) return 0; // Modular inverse doesn't exist
    while (a > 1) {
        long long q = a / m;
        long long t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0) x += m0;
    return x;
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < room; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    inv_fact[room - 1] = mod_inverse(fact[room - 1], MOD);
    for (int i = room - 2; i >= 0; i--) {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }
}

int NcR(int n, int r) {
    if (r > n) return 0; // Return 0 if r > n
    return (fact[n] * inv_fact[r] % MOD) * inv_fact[n - r] % MOD;
}

long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod; 
    while (exp > 0) {
        if (exp % 2 == 1) { 
            result = (result * base) % mod;
        }
        base = (base * base) % mod; 
        exp /= 2; 
    }
    return result;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int k; 
    cin >> k;

    int res = 0;


    for (int i = room; i >0; i--) { 
        int n = mod_pow(2,i,room); //pow(2, i)
        if (n >= k) {
            res = (res + NcR(n, k)) % MOD;
        }
    }

    cout << res;

    return 0;
}

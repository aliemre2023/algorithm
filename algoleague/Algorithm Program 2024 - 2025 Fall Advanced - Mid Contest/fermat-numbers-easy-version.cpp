#include <bits/stdc++.h>
#define int long long
using namespace std;

int modExp(int base, int exp, int mod) {
    int result = 1;
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
    int N, M;
    cin >> N >> M;

    int mod_minus_1 = M - 1;
    int exponent = modExp(2, N, mod_minus_1);
    
    int result = modExp(2, exponent, M);
    
    result = (result + 1) % M;

    cout << result << endl; 
    return 0;
}

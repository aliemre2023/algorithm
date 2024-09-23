#include <bits/stdc++.h>

using namespace std;
#define int long long

int marker(int n, const vector<bool>& prime) {
    int total = 0; 
    int i = 1;
    int pluser = 1;
    int counter = -1;
    vector<int> marked(n + 1, 0); 

    while (i <= n) {
        //cout << i << " " << pluser << " " << counter << "\n";
        counter++;
        marked[i] = 1;
        if (prime[i]) {
            total += i;
        }
        if (counter != 0 && counter % 2 == 0) {
            pluser += 1;
        }
        i += pluser;
    }
    
    return total; 
}

vector<bool> SieveOfEratosthenes(int n) {
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false; 

    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }
    
    return prime;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<bool> sieve = SieveOfEratosthenes(n * n);
    int res = marker(n * n, sieve);
    
    cout << res << endl;

    return 0;
}

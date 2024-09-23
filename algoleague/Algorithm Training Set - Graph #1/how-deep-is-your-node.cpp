#include <bits/stdc++.h>
using namespace std;



// Driver code
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    vector<int> parent(n + 1);
    for (int i = 2; i <= n; i++) {
        int x; cin >> x;
        parent[i] = x; 
    }
    
    int k; cin >> k;
    

    int depth = 0;

    while (k != 1) {
        k = parent[k];
        depth++;
    }
    cout << depth;
    
    return 0;
}

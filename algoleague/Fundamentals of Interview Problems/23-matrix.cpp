//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
// write your code here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    
    
    int max_sum = INT_MIN;
    int prefix_sum = 0;
    int min_prefix_sum = 0;
    
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        prefix_sum += x;
        
        max_sum = max(max_sum, prefix_sum - min_prefix_sum);
        
        min_prefix_sum = min(min_prefix_sum, prefix_sum);
    }
    
    
    cout << max_sum;
	return 0;
}

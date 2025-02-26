//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
// write your code here
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int q; cin >> q;
    for(int _ = 0 ; _ < q; _++){
        int n; cin >> n; 
        vector<int> arr;
        for(int i = 0; i < 2*n; i++){
            int x; cin >> x;
            arr.push_back(x);
            
        }
        sort(arr.begin(), arr.end());
        
        int diff = 0;
        for(int i = 0; i< 2*n; i += 2){
            diff += arr[i+1] - arr[i];
        }
        
        cout << diff << "\n";
    }
	return 0;
}

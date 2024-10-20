#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main() {
    // write your code here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int q; cin >> q;
    vector<int> arr;
    int back = 0;
    for(int i = 0;i < q; i++){
        int x; cin >> x;
        arr.push_back(x + back);
        back = arr[arr.size()-1];
    }
    
    
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        
        int idx = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
        if(arr[idx-1] == x){
            cout << idx-1 << "\n";
        }
        else{
            cout << idx << "\n";
        }
        
    }
    
    
    return 0;
}

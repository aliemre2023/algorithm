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

    unordered_map<string, int> mp;
    
    for(int i = 0; i < n; i++){
        int q; cin >> q;
        string book; cin >> book;
        if(q == 2){
            mp[book] += 1; 
        }
        else if(q == 1){
            if(mp[book] >= 1){
                cout << "YES\n";
                mp[book] -= 1;
            } 
            else{
                cout << "NO\n";
            }
        }
    }
    
	return 0;
}
//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

#define int long long
int32_t main() {
// write your code here
    
    int MOD = 1e9+7;
    
    int n; cin >> n;
    int z = 0;
    int e = 0;
    int r = 0;
    int o = 0;

    for(int i = 0; i < n; i++){
        char c; cin >> c;
        if(c == 'z'){
            z = 1 + z;
        }
        if(c == 'e'){
            e = z + e;
        }
        if(c == 'r'){
            r = e + r;
        }
        if(c == 'o'){
            o = (r + o)%MOD;
        }
    }
    cout << o;
	return 0;
}

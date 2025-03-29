// A - Kamilka and the Sheep

#include <iostream>

using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q; cin >> q;

    while(q--){
        int n; cin >> n;

        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            mini = min(mini, x);
            maxi = max(maxi, x);
        }

        cout << maxi - mini << "\n";
    }

    return 0;

}
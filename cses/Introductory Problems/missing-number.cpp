#include <iostream>

using namespace std;
#define int long long

int32_t main(){
    int n; cin >> n;

    int tot = 0;
    for(int i = 0; i < n-1; i++){
        int x; cin >> x;
        tot += x;
    }

    int real_tot = ((n+1)*n)/2;

    cout << real_tot - tot;

    return 0;
}
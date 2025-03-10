#include <iostream>

using namespace std;
#define int long long

int32_t main(){
    int n; cin >> n;

    int prev; cin >> prev;
    int res = 0;

    for(int i = 0; i < n-1; i++){
        int curr; cin >> curr;

        if(curr < prev){
            res += (prev - curr);
        }
        else{
            prev = curr;
        }

    }

    cout << res;

    return 0;
}
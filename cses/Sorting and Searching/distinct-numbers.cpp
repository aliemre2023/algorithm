#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define int long long

int32_t main(){
    int n; cin >> n;

    vector<int> arr;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());

    int p = 0;
    int count = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == p){
            continue;
        }
        count += 1;
        p = arr[i];
    }

    cout << count;

    return 0;
}
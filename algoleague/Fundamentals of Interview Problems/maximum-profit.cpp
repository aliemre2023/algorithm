#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    
    vector<int> arr;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        arr.push_back(x);
    }
    
    int mini = arr[0];
    int profit = 0;
    for(int i = 1; i < n; i++){
        if(arr[i] < mini){
            mini = arr[i];
        }
        else{
            profit = max(profit, arr[i] - mini);
        }
    }
    cout << profit;

    return 0;
}

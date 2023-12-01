#include <bits/stdc++.h>
using namespace std;

int zero_finder = 0;
using ll = long long;

void subsetMinSum(vector<int>& arr, int l, int r, ll sum, ll& minSum) {
    if (l > r ) {
        if(sum != 0 && zero_finder == 0){
            minSum = min(minSum, abs(sum));
        }
        if(zero_finder){
            minSum = min(minSum, abs(sum));
        }
        if(sum == 0) zero_finder = 1;
        
        return;
    }

  
    subsetMinSum(arr, l + 1, r, sum + arr[l], minSum);
    subsetMinSum(arr, l + 1, r, sum, minSum);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll minSum = INT_MAX;
    subsetMinSum(arr, 0, n - 1, 0, minSum);
    
    cout << minSum;

    return 0;
}

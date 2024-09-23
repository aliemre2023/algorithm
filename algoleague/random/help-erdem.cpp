//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
// write your code here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    
    vector<int> dp(n, 1);
    vector<int> arr;
    for(int i =0 ; i < n; i++){
        int x; cin >> x;
        arr.push_back(x);
    }
    
    int maxi = 0;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] >= arr[j]){
                dp[i] = max(dp[i], dp[j]+1);
                maxi = max(dp[i], maxi);
            }
        }
    }
    cout << maxi;
    
	return 0;
}

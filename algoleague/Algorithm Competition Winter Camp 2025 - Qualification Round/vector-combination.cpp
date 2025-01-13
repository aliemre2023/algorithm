//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>
#define int long long

using namespace std;

bool findable(vector<vector<int>>& arr, vector<int>& curr, vector<int>& target, int index, int N, int D) {
    bool matches = true;
    for(int d = 0 ; d < D; d++) {
        if(curr[d] != target[d]) {
            matches = false;
            break;
        }
    } //
    if(matches) return true;
    
    // final
    if(index >= N) return false;
    
    if( findable(arr, curr, target, index + 1, N, D))  return true;
    for(int d = 0; d < D; d++) {
        curr[d] += arr[index][d];
    }
    
    if(findable(arr, curr, target, index + 1, N , D)) return true;
    for(int d = 0; d < D; d++) {
        curr[d] -= arr[index][d]; //cont
    }
    
    return false;
}


int32_t main() {
// write your code 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    
    int n, k; cin >> n >> k;
    
    vector<vector<int>> arr;
    for(int i =0 ; i< n;i++){
        vector<int> temp;
        for(int j = 0; j < k; j++){
            int x; cin >> x;
            temp.push_back(x);
        }
        arr.push_back(temp);
    }
    
    vector<int> target;
    for(int i = 0;i < k; i++){
        int x; cin >> x;
        target.push_back(x);
    }
    
    
    vector<int> curr(k, 0);
    
    bool res = findable(arr, curr,target, 0, n, k);
    if(res) cout << "YES";
    else cout << "NO";
    

	return 0;
}

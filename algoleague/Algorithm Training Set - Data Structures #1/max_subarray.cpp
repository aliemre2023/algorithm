//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
// write your code here
    int n, k; cin >> n >> k;
    vector<int> arr;
    
    int maxim = 0;
    int total = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(i >= k){
            total += x;
            total -= arr[i-k];
            arr.push_back(x);
        }
        else{
            arr.push_back(x);
            total += x;
        }
        if(total > maxim) maxim = total;
    }
    cout << maxim;
	return 0;
}

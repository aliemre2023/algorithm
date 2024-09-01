//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
// write your code here
    int n, m; cin >> n >> m;
    vector<int> arr;
    for(int i =0 ; i< n; i++){
        int c; cin >>c;
        arr.push_back(c);
    }
    

    if(arr[0] == 0 && arr[1] == 0){
        arr[0] = 1;
        m--;
    }
    if(m <= 0) {
        cout << "Yes";
        return 0;
    }
    if(arr[n-1] == 0 && arr[n-2] == 0){
        arr[n-1] = 1;
        m--;
    }
    if(m <= 0) {
        cout << "Yes";
        return 0;
    }
    for(int i = 1; i < n-1; i++){
        int r = arr[i-1];
        int mid = arr[i];
        int l = arr[i+1];
        
        if(r == 0 && mid == 0 && l == 0){
 
            arr[i] = 1;
            m--;
        }
        if(m <= 0){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
	return 0;
}

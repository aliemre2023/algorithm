//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
// write your code here
    int n; cin >> n;
    
    vector<int> arr(n+1,0);
    int c; cin >> c;
    arr[0] = c;
    int temp = c;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        arr[i+1] = x - temp;
        temp = x;
    }
    
    int min = INT_MAX;
    for(int i = 1; i < n; i++){
        if(min > arr[i]) min = arr[i];
    }
    if(min >= 0) cout << min + 1;
    else cout << 1;
    
    
	return 0;
}

//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
// write your code here
    int n; cin >> n;
    int en; cin >> en;
    
    vector<int> arr;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        arr.push_back(x);
    }
    
    sort(arr.begin(), arr.end());
    arr.push_back(0);
    
    for(int i = 0; i < n; i++){
        en -= arr[i];
        if(en < 0){
            cout << i+1;
            break;
        }
    }
    if(en >= 0){
        cout << "EV";
    }
    
}

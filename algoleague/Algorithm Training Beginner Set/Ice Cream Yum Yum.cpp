//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int total = 0;
    int minim = INT_MAX;
    vector<int> arr;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        total += x;
        
        if(minim > x) minim = x;
        
    }
    cout << total - minim;
    
    

	return 0;
}

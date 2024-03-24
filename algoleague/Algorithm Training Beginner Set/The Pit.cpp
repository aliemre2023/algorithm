//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;
#define int long long

void decToBinary(int n, int x){
    
    for (int i = x-1; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            cout << "1";
        else
            cout << "0";
    }
    cout << "\n";
}

int32_t main(){
    
    int x; cin >> x;
    
    int pw = pow(2,x);
    for(int i = 0; i < pw; i++){
        decToBinary(i, x);
    }
}

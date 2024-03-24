//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main() {
// write your code here
    int n; cin >> n;
    int m; cin >> m;
    int hold_m = m;
    
    
    int wuh = n + n - 2;
    
    int sth = 1+wuh; // sth = 11
    while(m > sth){
        sth += wuh; // sth = 21;
    }
    sth -= wuh; // sth = 11;
    m -= sth; // = 20 - 11 = 9
    m += 1; // m = 10;
    
    if(m > n){ // true 10 > 6
        m = (2*n) -m; // 12 - 10 doğru
    }
    
    
    
    
    int adder;
    adder = m / 2;
    m += adder;
    if(hold_m % 2 == 1){
        
        cout << m;
    }
    else{
        cout << m-1 << " " << m;
    }
    

	return 0;
}

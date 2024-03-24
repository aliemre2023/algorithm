//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>
#define int long long
using namespace std;

int func(int n){
    string str = to_string(n);
    int c;
    int final = 1;
    for(int i = 0 ; i < str.size(); i++){
        c = str[i] - '0';
        if(c != 0){
            final *= c;
        }
    }
    return final;
}



int32_t main() {
// write your code here
    int n; cin >> n;
    
    while(n > 9){
        n = func(n);
    }
    cout << n;
    
    
	return 0;
}

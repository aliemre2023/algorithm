// Question Link = https://algoleague.com/contest/itu-acm-algo101-final-contest/problem/buddies-and-busses/

//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int EKOK(int a, int b){
    int bigone = max(a,b);
    int res = bigone;
    for(int i = bigone; i <= a*b; i++){
        if(i % a == 0 && i % b == 0){
            res = i;
            return res;
        }
    }
    return res;
}

int main() {
// write your code here
    int q;
    cin >> q;
    
    for(int i = 0; i < q; i++){
        int t, t1, t2;
        cin >> t >> t1 >> t2;
        
        int ekok = EKOK(t1,t2);
        
        int carpici = 0;
        while(86400 > ekok * carpici){
            carpici++;
            if(86400 > ekok * carpici && ekok * carpici >= t){
                cout << ekok * carpici << "\n";
                break;
            }
        }
        if(86400 <= ekok * carpici){
            cout << "-1" << "\n";
        }
        
    }
    

	return 0;
}

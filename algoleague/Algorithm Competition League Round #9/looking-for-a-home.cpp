//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
// write your code here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    for(int i = 0; i< n; i++){
        int x, y; cin >> x >> y;
        
        int m = 1;
        int c = 0;
        while(m < x){
            if(c%2 == 0){
                m += 2;
            }
            else{
                m += 1;
            }
            c++;
        }
        int k = 1;
        c = 0;
        while(k < y){
            if(c%2 == 0){
                k += 2;
            }
            else{
                k += 1;
            }
            c++;
        }
        
        if(m == x || k == y){
            cout << 1 << "\n";
        }
        else{
            cout << 0 << "\n";
        }
    }
	return 0;
}


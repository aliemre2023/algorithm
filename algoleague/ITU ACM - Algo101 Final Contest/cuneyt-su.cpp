//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
// write your code here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int s = 0;
    int res = 0;
    
    for(int i = 0; i < n; i++){
        char c; cin >> c;
        if(c == 'S'){
            s++;
        } 
        else{
            if(s > 0){
                s--;
                res++;
            }
        }
    }
    cout << res;
	return 0;
}
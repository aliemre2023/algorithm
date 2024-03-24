//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
// write your code here
    int n; cin >> n;
    int k; cin >> k;
    
    int h = 0;
    int s = 0;
    for(int i = 0; i < k; i++){
        char x; cin >> x;
        if(x == 'H'){
            h++;
        }
        else{
            s++;
        }
    }
    if(h > n/2){
        cout << "Harun";
    }
    else if(s > n/2){
        cout << "Sami";
    }
    else{
        cout << "Cilek";
    }

	return 0;
}

//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
// write your code here
    int n; cin >> n;
    char prev;
    char curr;
    cin >> curr;
    cout << curr;
    for(int i = 1; i < n; i++){
        prev = curr;
        cin >> curr;
        if(prev != curr){
            cout << curr;
        }
    }

	return 0;
}

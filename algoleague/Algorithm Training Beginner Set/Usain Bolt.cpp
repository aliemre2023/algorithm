//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
// write your code here
    int n; cin >> n;
    int counter = 0;
    
    int record;
    int curr;
    cin >> record;
    
    for(int i = 1; i < n; i++){
        cin >> curr;
        if(curr > record){
            counter++;
            record = curr;
        }
    }
    cout << counter;
    

	return 0;
}

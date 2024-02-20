//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
// write your code here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string arr;
    cin >> arr;
    
    for(int i = 0; i < arr.size()-5; i++){
        if(arr.size() < 6) break;
        if(arr.size() > 5 && arr[i] == 'B' && arr[i+1] == 'U' && arr[i+2] == 'C' && arr[i+3] == 'O' && arr[i+4] == 'D' && arr[i+5] == 'E'){
            arr.erase(i, 6);
            i--;
        }
    }
    if(arr.size() == 0){
        cout << "UTKU";
    }
    else{
        cout << arr;
    }
	return 0;
}

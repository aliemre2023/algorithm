//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
// write your code here
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int x,y; cin >> x >> y;
    vector<int> arr;
    int is_first_odd = -1; // if ok 1;
    for(int i =0 ; i<x; i++ ){
        int a; cin >> a;
        if(is_first_odd == -1){
            if(a%2){
                is_first_odd = 1;
            }
            else{
                is_first_odd = 0;
            }
        }
        if(is_first_odd == 1 && a%2 == 0){
            cout << "NO";
            return 0;
        }
        if(is_first_odd == 0 && a%2 == 1){
            cout << "NO";
            return 0;
        }
        
        
        arr.push_back(a);
    }
    cout << "YES";
	return 0;
}

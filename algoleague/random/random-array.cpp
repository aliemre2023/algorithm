//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
// write your code here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    
    
    int count = 0;
    int n; cin >> n;
    vector<bool> arr(6000,false);
    for(int i = 0; i < n; i++){
        int num; cin >> num;
        while(arr[num]){
            num += 1;
            count += 1;
        }
        arr[num] = true;
    }
    cout << count;
	return 0;
}

//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
// write your code here
    priority_queue<int> q; 
    
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int query; cin >> query;
        if(query == 1){
            int x; cin >> x;
            q.push(x);
        }
        if(query == 2){
            if(q.empty()){
                cout << -1 << "\n";
            }
            else{
                int temp = q.top();
                q.pop();
                cout << temp << "\n";
            }
        }
    }
	return 0;
}

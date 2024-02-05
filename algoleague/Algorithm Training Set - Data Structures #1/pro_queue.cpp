//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
// write your code here
    priority_queue<int> pq;
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        int s; cin >> s;
        
        if(s == 1){
            int x; cin >> x;
            pq.push(x);
        }
        if(s == 2){
            if(pq.empty()){
                cout << -1 << "\n";
            }
            else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }
}
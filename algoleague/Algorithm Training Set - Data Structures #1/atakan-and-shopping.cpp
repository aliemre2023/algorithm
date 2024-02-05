//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
// write your code here
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    
    priority_queue<int> pq;
    
    int n, m; cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        pq.push(x);
    }
    for(int i = 0; i < m; i++){
        int temp = pq.top() / 2;
        pq.pop();
        pq.push(temp);
    }
    long long total = 0;
    for(int i = 0; i < n; i++){
        total += pq.top();
        pq.pop();
    }
    cout << total;
	return 0;
}

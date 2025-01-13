#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
#define int long long


int32_t main() {
    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 


    int n, k; cin >> n >> k;
    queue<string> q; 
    for(int i = 0; i < n; i++){
        string name; cin >> name;;
        q.push(name);
    }
    
    
    int counter = 0;
    while(!q.empty()){
        string name = q.front(); 
        q.pop();
        cout << name << "\n";
        counter += 1;
        
        if (counter == k && !q.empty()) {
            counter = 0;
            string repair = q.front();
            q.pop();
            q.push(repair);
        }
        
    }
}
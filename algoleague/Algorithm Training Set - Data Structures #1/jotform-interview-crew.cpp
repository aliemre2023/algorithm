//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;
#define int long long int

int32_t main() {
// write your code here
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    
    int n; cin >> n;
    
    
    map<char, bool> occur;
    queue<char> pitch;
    stack<char> bench;
    for(int i = 0; i < n; i++){
        char x; cin >> x;
        
        if(occur.find(x) == occur.end()){
            if(x == '-'){
                if(!pitch.empty()){
                    bench.push(pitch.front());
                    pitch.pop();
                }
            }
            else if(x == '+'){
                if(!bench.empty()){
                    pitch.push(bench.top());
                    bench.pop();
                }
            }
            else{
                occur[x] = true;
                pitch.push(x);
            }
        }
    }
    
    stack<char> res;
    while (!pitch.empty()){
        res.push(pitch.front());
        pitch.pop();
    }
    while (!res.empty()){
        cout << res.top() << " ";
        res.pop();
    }
        
	return 0;
}

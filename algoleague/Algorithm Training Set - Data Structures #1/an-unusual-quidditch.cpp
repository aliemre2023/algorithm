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
    
    vector<int> weight;
    vector<char> direct;
    
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        weight.push_back(x);
    }
    for(int i = 0; i < n; i++){
        char x;
        cin >> x;
        direct.push_back(x);
    }
    
    int res = 0;
    
    stack<int> st;
    for(int i = 0; i < n; i++){
        if(direct[i] == 'R'){
            st.push(weight[i]);
        }
        else{
            if(!st.empty()){
                while(!st.empty() && st.top() < weight[i]){
                    st.pop();
                }
                if(!st.empty() && weight[i] == st.top()){
                    st.pop();
                }
                else{
                    if(st.empty()){
                        res++;
                    }
                }
            }
            else{
                res++;
            }
        }
    }
    
    res += st.size();
    cout << res;
    
	return 0;
}

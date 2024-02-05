//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
// write your code here
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    
    stack<string> st;
    
    int n; cin >> n;
    
    string x;
    for(int i = 0; i < n; i++){
        cin >> x;
        
        if(!st.empty() && st.top() == x){
            st.pop();
        }
        else{
            st.push(x);
        }
    }
    
    stack<string> st2;
    int size = st.size();
    for(int i = 0; i < size; i++){
        st2.push(st.top());
        st.pop();
    }
    for(int i = 0; i < size; i++){
        cout << st2.top() << " ";
        st2.pop();
    }
    
	return 0;
}
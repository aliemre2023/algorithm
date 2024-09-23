//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
// write your code here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string given; cin >> given;
    stack<char> st;
    for(auto c : given){
        if(c == '{' || c == '(' || c == '['){
            st.push(c);
        }
        else{
            if(!st.empty() && 
            ((st.top() == '{' && c == '}') ||
            (st.top() == '(' && c == ')') ||
            (st.top() == '[' && c == ']'))){
                st.pop();
            }
            else{
                cout << "NO";
                return 0;
            }
        }
    }
    if (st.empty()) {
        cout << "YES";
    } 
    else {
        cout << "NO";
    }
    
    
	return 0;
}

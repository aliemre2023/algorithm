#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    int f; cin >> f;

    vector<stack<int>> st(6); 
    int res = 0;

    for(int i = 0; i < n; i++){
        int me, to;
        cin >> me >> to;
        int a = me - 1;

        if(!st[a].empty() && st[a].top() < to){
            res++;
            st[a].push(to);
        } 
        else if(!st[a].empty() && st[a].top() > to){
            while(!st[a].empty() && st[a].top() > to){
                res++;
                st[a].pop(); //
            }
            if(!st[a].empty() && to > st[a].top()){
                res++;
                st[a].push(to);
            }
            if(st[a].empty()){
                res++;
                st[a].push(to);
            }
        } 
        else{
            if(!st[a].empty()){
                if(st[a].top() != to){
                    res++;
                    st[a].push(to);
                }
            }
            else{
                res++;
                st[a].push(to);
            }
        }
        //cout << res << "\n";
    }

    cout << res << "\n";
    return 0;
}

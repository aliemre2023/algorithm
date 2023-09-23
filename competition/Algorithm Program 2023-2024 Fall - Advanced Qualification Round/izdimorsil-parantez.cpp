// Question Link = https://algoleague.com/contest/algorithm-program-2023-2024-fall-advanced-qualification-round/problem/izdimorsil-parantez/

//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
// write your code here
    stack<int> pts;
    
    int n; cin >> n;
    
    string str;
    cin >> str;
    int wrd = 0;
    for(int i = 0 ;i < n; i++){
        char w = str[i];
        if(w == '(' || w == '[' || w == '{'){
            pts.push(w);
            wrd++;
            if(wrd == n / 2){
                cout << "NO";
                return 0;
            }
        }
        else if(pts.empty()){
            cout << "NO";
            return 0;
        }
        else{
            wrd = 0;
            char top = pts.top();
            pts.pop();
            
            if ((w == ')' && top != '(') || (w == ']' && top != '[') || (w == '}' && top != '{')) {
                cout << "NO";
                return 0;
            }
        }
    }
    
    if(pts.empty()) cout << "YES";
    else cout << "NO";
    
    
	return 0;
}

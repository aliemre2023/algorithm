//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;
#define int long long int

int32_t main() {
// write your code here
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    
    int n;
    cin >> n;

    vector<string> inputVector;
    string inputString;
  
    cin.ignore();
    getline(cin, inputString);

    istringstream ss(inputString);
    string o;
    
    while (getline(ss, o, ' ')) {
        inputVector.push_back(o);
    }

    
    map<string, bool> occur;
    queue<int> pitch;
    stack<int> bench;
    for(int i = 0; i < n; i++){
        string x = inputVector[i];
        if(x == "-"){
            if(!pitch.empty()){
                bench.push(pitch.front());
                pitch.pop();
            }
        }
        else if(x == "+"){
            if(!bench.empty()){
                pitch.push(bench.top());
                bench.pop();
            }
        }
        else if(occur.find(x) == occur.end()){
            int xx = stoi(x);
            occur[x] = true;
            pitch.push(xx);
        }
    }
    
    stack<int> res;
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

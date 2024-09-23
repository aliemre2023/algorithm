//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
// write your code here
    
    int nodes; cin >> nodes;
    int edges; cin >> edges;
    
    vector<int> res(nodes, 0);
    
    for(int i = 0; i < edges; i++){
        int x, y; cin >> x >> y;
        res[x-1]++;
        res[y-1]++;
    }
    
    for(int i = 0; i < res.size(); i++){
        cout << res[i] <<  " ";
    }
    
    

	return 0;
}

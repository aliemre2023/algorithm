//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
// write your code here

    int nodes; cin >> nodes;
    int edges; cin >> edges;
    
    vector<vector<int> > adjM(nodes, vector<int>(nodes, 0));
    vector<vector<int> > adjL(nodes, vector<int>(1, 0));

    for(int i=0; i<nodes; i++){
        for(int j=0; j<nodes; j++){
            adjM[i][j] = 0;
        }
    }
  
    for(int i = 0; i < edges; i++){
        //
        int x, y; cin >> x >> y;
        
        adjM[x-1][y-1]++;
        adjM[y-1][x-1]++;
        //
        
        adjL[x-1].push_back(y);
        adjL[y-1].push_back(x);
        
    }
    
    for(int i=0; i<adjL.size(); i++){
        sort(adjL[i].begin(), adjL[i].end());
        for(int j=1; j<adjL[i].size(); j++){
            cout << adjL[i][j] << " ";
        }
        cout << "\n";
    }
    
    for(int i=0; i<adjM.size(); i++){
        for(int j=0; j<adjM[i].size(); j++){
            cout << adjM[i][j] << " ";
        }
        cout << "\n";
    }
    
    

	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m; 
    cin >> n >> m;
    
    map<int,int> storage;
    vector<int> last;
    int del = 0;

    for(int i = 0; i < n; i++) {
        string s; 
        cin >> s;
        
        if(s == "put") {
            int x, y; 
            cin >> x >> y;
            if(storage.size() < m) {
                storage[x] = y;
                last.push_back(x);
            } else {
                while(del < last.size()) {
                    if(storage.find(last[del]) != storage.end()) {
                        storage.erase(last[del]);
                        del++;
                        break;
                    }
                    del++;
                }
                storage[x] = y;
                last.push_back(x);
            }
        } else {
            int x; 
            cin >> x;
            if(storage.find(x) != storage.end()) {
                cout << storage[x] << "\n";
                
                last.erase(remove(last.begin(), last.end(), x), last.end());
                last.push_back(x);
            } else {
                cout << -1 << "\n";
            }
        }
    }

    return 0;
}

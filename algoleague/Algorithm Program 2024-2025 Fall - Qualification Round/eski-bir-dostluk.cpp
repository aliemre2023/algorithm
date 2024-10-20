#include <bits/stdc++.h>

using namespace std;

int main() {
    // write your code here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> char_val(26);
    map<int, string> players;

    for (int i = 0; i < 26; i++) {
        int x; 
        cin >> x;
        char_val[i] = x; // Use direct assignment instead of push_back
    }
    
    int q; 
    cin >> q;
    for (int i = 0; i < q; i++) {
        int w; 
        cin >> w;
        if (w == 1) {
            string name; 
            cin >> name;
            int curr_point = 0;
            for (auto it : name) {
                curr_point += char_val[it - 'a'];
            }
            curr_point %= 101;
            int origin = curr_point;
            
            bool recorded = false;
            if (players.find(curr_point) == players.end()) {
                players[curr_point] = name;
                recorded = true;
                cout << curr_point << "\n";
            } 
            curr_point += 1;
            curr_point %= 101; // Move this line outside the else statement
            if (!recorded && players.find(curr_point) == players.end()) { // Corrected this to be an if statement
                players[curr_point] = name;
                recorded = true;
                cout << curr_point << "\n";
            }
            curr_point += 3;
            curr_point %= 101; // Move this line outside the else statement
            if (!recorded && players.find(curr_point) == players.end()) { // Corrected this to be an if statement
                players[curr_point] = name;
                cout << curr_point << "\n";
                recorded = true;
            }
            curr_point += 5;
            curr_point %= 101; 
            if (!recorded && players.find(curr_point) == players.end()) { // Corrected this to be an if statement
                players[curr_point] = name;
                recorded = true;
                cout << curr_point << "\n";
            }
            
            if (!recorded) {
                players[origin] = name; 
                cout << origin << "\n";
            }
        } else if (w == 2) {
            int point; 
            cin >> point;
            
            if (players.find(point) != players.end()) {
                cout << players[point] << "\n";
            } else {
                cout << "ah be abi\n";
            }
        }
    }
    return 0;
}

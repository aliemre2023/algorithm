// Brace your keyboard
// inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> m >> n;

    vector<int> frow(n);
    for (int i = 0; i < n; i++) {
        cin >> frow[i];
    }
    vector<int> fcol(m);
    for (int i = 0; i < m; i++) {
        cin >> fcol[i];
    }

  
    vector<vector<int>> enc_grid(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> enc_grid[i][j];
        }
    }

    vector<vector<int>> org_grid(m, vector<int>(n, 0));
    for (int j = 0; j < n; j++) {
        org_grid[0][j] = frow[j];
    }
    for (int i = 0; i < m; i++) {
        org_grid[i][0] = fcol[i];
    }

    // logic
    int col_xor = 0;
    for (int r = 0; r < m; r++) {
        col_xor ^= org_grid[r][0];
    }
    //cout << "COL XOR : " << col_xor << "\n";
    for (int i = 1; i < m; i++) {
        int row_xor = 0;
        for (int c = 0; c < n; c++) {
            row_xor ^= org_grid[i-1][c];
            
        }
        //cout << "ROW XOR : " << row_xor << "\n";
        for (int j = 1; j < n; j++) {
            int rem_row = enc_grid[i-1][j] ^ row_xor;
            int new_col_xor = rem_row ^ org_grid[i-1][j];
            //cout << "new_col_xor : " << new_col_xor << "\n";
            
            int rem_col = enc_grid[i][0] ^ col_xor;
            int new_row_xor = rem_col ^ org_grid[i][0];
            //cout << "new_row_xor : " << new_row_xor << "\n";

            //int two_times_xored = new_row_xor ^ new_row_xor;
            //cout << "enc : " << enc_grid[i][j] << "\n";
            org_grid[i][j] = enc_grid[i][j]  ^ new_row_xor ^ new_col_xor;
        }
    }


    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << org_grid[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

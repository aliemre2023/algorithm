#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<pair<int, int>, int> counter;
    set<pair<int, int>> bi;

    int n, m; 
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        pair<int, int> edge = {x, y};
        pair<int, int> edgR = {y, x};

        if (counter.find(edge) != counter.end()) {
            continue;
        }
        else if (counter.find(edgR) != counter.end()) {
            if (x < y) {
                bi.insert(edge);
            } else {
                bi.insert(edgR);
            }
        }
        else {
            counter[edge]++;
        }
    }

    cout << bi.size() << "\n";
    for (const auto& p : bi) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}

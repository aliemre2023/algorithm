#include <bits/stdc++.h>

using namespace std;
#define int long long

class SegmentTree {
public:
    vector<int> tree;
    int size;

    SegmentTree(int n) {
        size = n;
        tree.resize(4 * n, 0);
    }

    void update(int idx, int value) {
        updateUtil(1, 1, size, idx, value);
    }

    void updateUtil(int node, int start, int end, int idx, int value) {
        if (start == end) {
            tree[node] += value; 
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                updateUtil(node * 2, start, mid, idx, value);
            } else {
                updateUtil(node * 2 + 1, mid + 1, end, idx, value);
            }
            tree[node] = tree[node * 2] + tree[node * 2 + 1]; 
        }
    }

    int query(int idx) {
        return queryUtil(1, 1, size, idx);
    }

    int queryUtil(int node, int start, int end, int idx) {
        if (end <= idx) return tree[node];
        if (start > idx) return 0;
        int mid = (start + end) / 2;
        return queryUtil(node * 2, start, mid, idx) + queryUtil(node * 2 + 1, mid + 1, end, idx);
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; 
    cin >> n;

    vector<pair<int, int>> dish, spon;

    for (int i = 0; i < n; i++) {
        int x; 
        cin >> x;
        dish.push_back({x, i + 1});  
    }

    for (int i = 0; i < n; i++) {
        int x; 
        cin >> x;
        spon.push_back({x, i + 1}); 
    }

    sort(dish.begin(), dish.end());
    sort(spon.begin(), spon.end());

    vector<int> res(n + 1, 0);  
    
    for (int i = 0; i < n; i++) {
        int dishIdx = dish[i].second; 
        int sponIdx = spon[i].second;  
        res[dishIdx] = sponIdx;
    }

    SegmentTree segTree(n); 

    for (int i = 1; i <= n; i++) {
        int countLess = segTree.query(res[i] - 1); 
        cout << res[i] - countLess << "\n"; 
        segTree.update(res[i], 1); 
    }

    return 0;
}

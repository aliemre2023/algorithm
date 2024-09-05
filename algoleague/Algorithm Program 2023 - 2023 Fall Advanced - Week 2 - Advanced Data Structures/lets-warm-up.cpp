#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    vector<int> tree;
    int n;
    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n, 0);  // Initialize tree with 0
    }
    void build(vector<int>& arr, int start, int end, int node) {
        if (start == end) {
            tree[node] = arr[start];  // Leaf node will have a single element
        } else {
            int mid = (start + end) / 2;
            build(arr, start, mid, 2 * node + 1);
            build(arr, mid + 1, end, 2 * node + 2);
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);  // Internal node will have the max of both children
        }
    }
    void update(int index, int value, int start, int end, int node) {
        if (start == end) {
            tree[node] = value;  // Update the leaf node
        } else {
            int mid = (start + end) / 2;
            if (index <= mid) {
                update(index, value, start, mid, 2 * node + 1);
            } else {
                update(index, value, mid + 1, end, 2 * node + 2);
            }
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);  // Update the internal node
        }
    }
    int query(int l, int r, int start, int end, int node) {
        // Completely outside the range
        if (r < start || l > end) {
            return 0;  // Return 0 for out of range
        }
        // Completely within the range
        if (l <= start && r >= end) {
            return tree[node];
        }
        // Partial overlap
        int mid = (start + end) / 2;
        int left_query = query(l, r, start, mid, 2 * node + 1);
        int right_query = query(l, r, mid + 1, end, 2 * node + 2);
        return max(left_query, right_query);
    }
};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    SegmentTree segTree(n);
    segTree.build(a, 0, n - 1, 0);

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int index, value;
            cin >> index >> value;
            segTree.update(index, value, 0, n - 1, 0);
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;
            cout << segTree.query(l, r, 0, n - 1, 0) << endl;
        }
    }
    return 0;
}

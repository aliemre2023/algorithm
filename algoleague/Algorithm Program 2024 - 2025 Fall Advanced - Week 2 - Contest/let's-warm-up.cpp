#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2*1e5 + 7;
int arr[N], tree[4 * N];

void build(int curr, int left, int right) {
    if (left == right) {
        tree[curr] = arr[left];
        return;
    }
    int mid = left + (right - left) / 2;
    build(2 * curr, left, mid);
    build(2 * curr + 1, mid + 1, right);
    tree[curr] = max(tree[2 * curr], tree[2 * curr + 1]);
}

void update(int curr, int left, int right, int i, int val) {
    if (left > i || right < i) {
        return;
    }
    if (left == right) {
        tree[curr] += val;
        arr[i] += val;
        return;
    }
    int mid = left + (right - left) / 2;
    update(2 * curr, left, mid, i, val);
    update(2 * curr + 1, mid + 1, right, i, val);
    tree[curr] = max(tree[2 * curr], tree[2 * curr + 1]);
}

int query(int curr, int left, int right, int curr_left, int curr_right) {
    if (curr_left > right || curr_right < left) {
        return LLONG_MIN;//
    }
    if (left <= curr_left && curr_right <= right) {
        return tree[curr];
    }
    int mid = (curr_left + curr_right) / 2;
    return max(query(2 * curr, left, right, curr_left, mid), query(2 * curr + 1, left, right, mid + 1, curr_right));
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    
    build(1, 1, n);
    
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        if (x == 1) {
            int idx, val;
            cin >> idx >> val;
            idx++;
            update(1, 1, n, idx, val);
        } 
        else if (x == 2) {
            int a, b;
            cin >> a >> b;
            a++;
            b++;
            int maxi = query(1, a, b, 1, n);
            cout << maxi << "\n";
        }
    }
    
    return 0;
}

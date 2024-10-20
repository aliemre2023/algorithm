#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 123;
int arr[N], constArr[N], tree[4 * N], activeArr[N], activeTree[4 * N];

void build(int curr, int left, int right) {
    if (left == right) {
        tree[curr] = arr[left];
        return;
    }
    int mid = left + (right - left) / 2;
    build(2 * curr, left, mid);
    build(2 * curr + 1, mid + 1, right);
    tree[curr] = tree[2 * curr] + tree[2 * curr + 1];
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
    tree[curr] = tree[2 * curr] + tree[2 * curr + 1];
}

int query(int curr, int left, int right, int curr_left, int curr_right) {
    if (curr_left > right || curr_right < left) {
        return 0;
    }
    if (left <= curr_left && curr_right <= right) {
        return tree[curr];
    }
    int mid = (curr_left + curr_right) / 2;
    return query(2 * curr, left, right, curr_left, mid) + query(2 * curr + 1, left, right, mid + 1, curr_right);
}

void build_Act(int curr, int left, int right) {
    if (left == right) {
        activeTree[curr] = activeArr[left];
        return;
    }
    int mid = left + (right - left) / 2;
    build_Act(2 * curr, left, mid);
    build_Act(2 * curr + 1, mid + 1, right);
    activeTree[curr] = activeTree[2 * curr] + activeTree[2 * curr + 1];
}

void update_Act(int curr, int left, int right, int i, int val) {
    if (left > i || right < i) {
        return;
    }
    if (left == right) {
        activeTree[curr] = val;
        activeArr[i] = val;
        return;
    }
    int mid = left + (right - left) / 2;
    update_Act(2 * curr, left, mid, i, val);
    update_Act(2 * curr + 1, mid + 1, right, i, val);
    activeTree[curr] = activeTree[2 * curr] + activeTree[2 * curr + 1];
}

int query_Act(int curr, int left, int right, int curr_left, int curr_right) {
    if (curr_left > right || curr_right < left) {
        return 0;
    }
    if (left <= curr_left && curr_right <= right) {
        return activeTree[curr];
    }
    int mid = (curr_left + curr_right) / 2;
    return query_Act(2 * curr, left, right, curr_left, mid) + query_Act(2 * curr + 1, left, right, mid + 1, curr_right);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        arr[i] = x;
        constArr[i] = x;
        activeArr[i] = 1; 
    }
    
    build(1, 1, n);
    build_Act(1, 1, n);
    
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        if (x == 1) {
            int idx;
            cin >> idx;
            if (activeArr[idx] == 0) {
                update(1, 1, n, idx, constArr[idx]);
                update_Act(1, 1, n, idx, 1);
            } else {
                update(1, 1, n, idx, -constArr[idx]);
                update_Act(1, 1, n, idx, 0);
            }
        } else if (x == 2) {
            int a, b;
            cin >> a >> b;
            int maxi = query(1, a, b, 1, n);
            int leng = query_Act(1, a, b, 1, n);
            if(leng != 0) cout << maxi/leng << "\n";
            else cout << -1 << "\n";
            
        }
    }
    
    return 0;
}
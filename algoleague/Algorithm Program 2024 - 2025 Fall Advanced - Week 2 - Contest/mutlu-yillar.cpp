#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 2 * 1e5 + 7;
int arr[N], sum_tree[4 * N], sqr_tree[4 * N];

void build(int curr, int left, int right) {
    if (left == right) {
        sum_tree[curr] = arr[left];
        sqr_tree[curr] = arr[left] * arr[left]; // sqr tree
        return;
    }
    int mid = left + (right - left) / 2;
    build(2 * curr, left, mid);
    build(2 * curr + 1, mid + 1, right);
    sum_tree[curr] = sum_tree[2 * curr] + sum_tree[2 * curr + 1];
    sqr_tree[curr] = sqr_tree[2 * curr] + sqr_tree[2 * curr + 1];
}

void update(int curr, int left, int right, int i, int val) {
    if (left > i || right < i) {
        return;
    }
    if (left == right) {
        sum_tree[curr] = val;
        sqr_tree[curr] = val * val;
        arr[i] = val;
        return;
    }
    int mid = left + (right - left) / 2;
    update(2 * curr, left, mid, i, val);
    update(2 * curr + 1, mid + 1, right, i, val);
    sum_tree[curr] = sum_tree[2 * curr] + sum_tree[2 * curr + 1];
    sqr_tree[curr] = sqr_tree[2 * curr] + sqr_tree[2 * curr + 1];
}

int query_sum(int curr, int left, int right, int curr_left, int curr_right) {
    if (curr_left > right || curr_right < left) {
        return 0;  // No effect
    }
    if (left <= curr_left && curr_right <= right) {
        return sum_tree[curr];
    }
    int mid = curr_left + (curr_right - curr_left) / 2;
    return query_sum(2 * curr, left, right, curr_left, mid) + query_sum(2 * curr + 1, left, right, mid + 1, curr_right);
}

int query_sqr(int curr, int left, int right, int curr_left, int curr_right) {
    if (curr_left > right || curr_right < left) {
        return 0;  // No effect
    }
    if (left <= curr_left && curr_right <= right) {
        return sqr_tree[curr];
    }
    int mid = curr_left + (curr_right - curr_left) / 2;
    return query_sqr(2 * curr, left, right, curr_left, mid) + query_sqr(2 * curr + 1, left, right, mid + 1, curr_right);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
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
            update(1, 1, n, idx, val);
        } 
        else if (x == 2) {
            int a, b;
            cin >> a >> b;
            
            int sum = query_sum(1, a, b, 1, n);
            int sqr_sum = query_sqr(1, a, b, 1, n);
            int len = b - a + 1;
            int average = sum / len;
            
            // Calculate variance, tf len*a*a?
            
            int variance = (sqr_sum - 2 * average * sum + len * average * average) / len;
            cout << variance << "\n";
        }
    }
    
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2e5 + 31;
int arr[N], tree[4 * N], lazy[4 * N];

void push(int i, int l, int r){
    tree[i] += lazy[i];
    
    // if i not leaf?
    if(l != r){
        lazy[2*i] += lazy[i];
        lazy[2*i+1] += lazy[i];
    }
    // info transferred to childs
    lazy[i] = 0;
}

void update(int i, int L, int R, int l, int r, int val){
    push(i, l, r);
    
    // out of interval
    if(r < L || R < l){
        return;
    }
    
    // totally in interval
    if(L <= l && r <= R){
        lazy[i] += val;
        push(i, l, r);
        return;
    }
    
    // if not totally find totally coveraged one
    int mid = (((r-l)/2) + l);
    update(2*i, L, R, l, mid, val);
    update(2*i+1, L, R, mid+1, r, val);
    
    // MAX seg tree
    tree[i] = max(tree[2*i], tree[2*i+1]);
}

int query(int i, int L, int R, int l, int r){
    push(i, l, r);
    
    // out of interval
    if(r < L || R < l){
        return INT64_MIN; // uneffective for MAX
    }
    
    // totally in interval
    if(L <= l && r <= R){
        return tree[i];
    }
    
    // if not totally in interval
    int mid = (((r-l)/2) + l);
    return max(query(2*i, L, R, l, mid), query(2*i+1, L, R, mid+1, r));
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, q; cin >> n >> q;
    for(int _ = 0; _ < q; _++){
        int type; cin >> type;
        
        if(type == 1){
            int i, j; cin >> i >> j;
            i++; j++;
            
            update(1, i, j, 1, n, 1);
        }
        if(type == 2){
            int i, j; cin >> i >> j;
            i++; j++;
            
            int res = query(1, i, j, 1, n);
            cout << res << "\n";
        }
    }

	return 0;
}

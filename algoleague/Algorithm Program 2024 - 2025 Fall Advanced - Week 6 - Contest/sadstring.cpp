#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
    TrieNode* child[26];
    int wordPassed;

    TrieNode() {
        wordPassed = 0;
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }
};

void insertKey(TrieNode* root, const string& key) {
    TrieNode* curr = root;

    for (char c : key) {
        if (curr->child[c - 'a'] == nullptr) {
            curr->child[c - 'a'] = new TrieNode();
        }
        curr = curr->child[c - 'a'];
        curr->wordPassed++; 
    }
}

vector<int> searchKey(TrieNode* root, const string& key) {
    vector<int> opt;
    TrieNode* curr = root;

    for (char c : key) {
        if (curr->child[c - 'a'] == nullptr) 
            return opt;
        curr = curr->child[c - 'a'];
        opt.push_back(curr->wordPassed);
    }
    return opt; 
}

struct Compare {
    bool operator()(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
        if (a.first.first == b.first.first) {
            return a.first.second > b.first.second;
        }
        return a.first.first > b.first.first;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    TrieNode* root = new TrieNode();
    int n, m;
    cin >> n >> m;

    vector<string> stri(n);
    for (int i = 0; i < n; i++) {
        cin >> stri[i];
        insertKey(root, stri[i]);
    }

    vector<int> arr(m+1);
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, Compare> pq;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        pq.push({{x, y}, i});
        arr[x] = max(arr[x], y);
    }

    vector<int> res(m);

    for(int i = 0; i < n; i++){
        vector<int> a = searchKey(root, stri[i]);

        while(!pq.empty() && pq.top().first.first == i+1){
            auto top = pq.top();
            pq.pop();

            if (top.first.second <= a.size()) {
                res[top.second] = a[top.first.second - 1];
            } else {
                res[top.second] = 0;
            }
        }
    }
    
    for(int i = 0; i < m; i++){
        cout << res[i] << "\n";
    }

    return 0;
}
//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
  
    // Array for child nodes of each node
    TrieNode* child[26];

    // for end of word
    bool wordEnd;

    TrieNode() {
        wordEnd = false;
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
    }
    curr->wordEnd = true;  // Mark the end of the word
}

bool searchKey(TrieNode* root, const string& key) {
    TrieNode* curr = root;
    for (char c : key) {
        if (curr->child[c - 'a'] == nullptr) 
            return false;
        curr = curr->child[c - 'a'];
    }
    //return curr->wordEnd;
    return true; // substr is ok
}

int main() {
// write your code here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    
    TrieNode* root = new TrieNode();
    map<string,int> added;
    
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        string s; cin >> s;
        if(x == 1){
            if(added.find(s) == added.end()){
                cout << "yes" << "\n";
                
                added[s] = 1;
                insertKey(root, s);
            }
            else{
                cout << "no" << "\n";
            }
        }
        else if(x == 2){
            if(added.find(s) != added.end()){
                cout << "yes" << "\n";
            }
            else{
                cout << "no" << "\n";
            }
        }
        else if(x == 3){
            if (searchKey(root, s)) 
                cout << "yes" << "\n";
            else 
                cout << "no" << "\n";   
            }
    }

	return 0;
}

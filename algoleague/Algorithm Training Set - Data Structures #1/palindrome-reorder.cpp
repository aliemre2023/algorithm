//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <map>
#include <vector>
#include <iostream>
#include <list>

using namespace std;
#define int long long int

int32_t main() {
// write your code here
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n; cin >> n;
    
    vector<int> mp(26, 0);
    for(int i = 0; i < n; i++){
        char x; cin >> x;
        int xx = x - 'A';
        mp[xx]++;
    }
    
    int odd = 0;
    for(int i = 0; i < mp.size(); i++){
        if(mp[i] % 2 == 1){
            odd++;
        }
    }
    
    if(n % 2 == 0 && odd > 0){
        cout << "NO SOLUTION";
        return 0;
    }
    if(n % 2 == 1 && odd > 1){
        cout << "NO SOLUTION";
        return 0;
    }
    //////
    
    char hold_odd;
    bool hold_odd_full = false;
    
    vector<char> res;
    for(int i = 0; i < mp.size(); i++){
        if(mp[i] > 1){
            while(mp[i] > 1){
                res.push_back(i);
                mp[i] -= 2;
            }
        }
        if(mp[i] == 1){
            hold_odd = i;
            hold_odd_full = true;
        }
    }

    int ressize = res.size();
    if(hold_odd_full){
        res.push_back(hold_odd);
    }
    
   
    for(int i = ressize - 1; i >= 0; i--){
        res.push_back(res[i]);
    }
    list<char> alphabet;
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        alphabet.push_back(ch);
    }
    for(int i = 0; i < res.size(); i++){
        auto it = next(alphabet.begin(), res[i]);
        cout << *it;
    }
    
    
	return 0;
}
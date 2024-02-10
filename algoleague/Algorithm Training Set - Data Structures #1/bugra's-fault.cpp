//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;


#define int long long int
int MOD = 1000000007;

int32_t main() {
// write your code here
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n; cin >> n;
    
    vector<char> op;
    vector<int> num;
    string str; cin >> str;
    int tot = 0;
    
    for(int i = 0; i < n; i++){
        char x = str[i];
        if(x == '*' || x == '+' || x == '-'){
            op.push_back(x);
            num.push_back(tot);
            tot = 0;

        }
        else{
            int x_int = x - '0';
            tot *= 10;
            tot += x_int;
        }
    }
    num.push_back(tot);

    
    vector<int> num2;
    vector<char> op2;
    
    num2.push_back(num[0]);
    for(int i = 0; i < op.size(); i++){
        if(op[i] == '*'){
            mult = true;
            int val = num[i] * num[i+1];
            while(i+1 < op.size() && op[i+1] == '*'){
                i++;
                val *= num[i+1];
            }
            
            num2.pop_back();
            num2.push_back(val);
            
            
        }
        else{
            op2.push_back(op[i]);
            num2.push_back(num[i+1]);

        }
    }

    int res = 0;
    res += num2[0] % MOD;
    for(int i = 0; i < op2.size(); i++){
        if(op2[i] == '-'){
            res -= num2[i+1];
            res = res % MOD;
        }
        else{
            res += num2[i+1];
            res = res % MOD;
        }
    }
    res += MOD;
    cout << res % MOD;
    
	return 0;
}

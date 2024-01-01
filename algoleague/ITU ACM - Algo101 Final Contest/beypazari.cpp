// Question Link = https://algoleague.com/contest/itu-acm-algo101-final-contest/problem/beypazari/

//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;
//typedef long long ll;
int main() {
// write your code here
    int x;
    cin >> x;
    
    vector<int> arr;
    for(int i = 0; i < x; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }
    int res = 0;
    vector<int> dp;
    dp.push_back(0);
    for(int i = 1; i < arr.size(); i++){
        int val = 0;
        for(int j = i-1; 0 <= j; j--){
            if(arr[i] > arr[j]){
                val = max(val, dp[j]+1);
            }
        }
        dp.push_back(val);
        res += val;
    }
    cout << res;
    

    
	return 0;
}

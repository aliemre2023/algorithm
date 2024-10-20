//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>
#define int long long
using namespace std;

map<int,int> mp;
int res = 0;

int lengthOfLIS(vector<int>& nums) {
    vector<int> sub;
    for (int x : nums) {
        if (sub.empty() || sub[sub.size() - 1] < x) {
            sub.push_back(x);
            res += mp[x];
        } else {
            auto it = lower_bound(sub.begin(), sub.end(), x);
            *it = x; 
        }
    }
    return sub.size();
}
int32_t main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int n; cin >> n;
    
    vector<pair<int,int>> arr;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        arr.push_back({x,y});
    }
    sort(arr.begin(), arr.end());
    

    if(arr.size() >= 10e3){
        vector<int> second;
        for(int i = 0; i < arr.size(); i++){
            //cout << arr[i].first << "-" <<  arr[i].second << "\n";
            second.push_back(arr[i].second);
            mp[arr[i].second]++;
        }
        
        
        
        int o = lengthOfLIS(second);
        
        cout << res;
    }

    else{
        vector<int> lis(n,1);
        for(int i = 0; i < n; i++){
            for(int j = i-1; j >= 0; j--){
                if(arr[i].second >= arr[j].second){
                    lis[i] = max(lis[j]+1, lis[i]);
                }
            }
        }
        
        
        
    
        int result = *max_element(lis.begin(), lis.end());
        cout << result << "\n";
    }
    
	return 0;
}
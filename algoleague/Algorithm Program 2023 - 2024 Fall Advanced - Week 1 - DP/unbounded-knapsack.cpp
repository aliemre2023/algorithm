// Question Link = https://algoleague.com/contest/algorithm-program-2023-2024-fall-advanced-week-1-dp/problem/unbounded-knapsack/

//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
// write your code here
    int n; cin >> n;
    int target; cin >> target;
    vector<int> nums;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        nums.push_back(x);
    }

    vector<int> dp(2*target, INT_MAX);
    dp[0] = 0;
    
    int ans;
    int distance = 0;
    for(int i = 0; i <= 2*target+1; i++){
        for(int j = 0; j < n; j++){
            if(i >= nums[j]){
                int temp = dp[i - nums[j]];
                if(temp != INT_MAX && temp + 1 < dp[i]){
                    dp[i] = temp + 1;
                    if(i < target){
                        ans = i;
                        distance = 0;
                    }
                    else if(i == target){
                        cout << target;
                        return 0;
                    }
                    else{
                        if(distance > (i - target)){
                            cout << i;
                            return 0;
                        }
                        else{
                            cout << ans;
                            return 0;
                        }
                    }
                    distance++;
                }
            }
        }
    }
	return 0;
}

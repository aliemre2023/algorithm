//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll largestRectangleArea(vector<ll>& heights) {
    vector<ll> arr;
    ll max_area = 0;
    ll index = 0;

    while (index < heights.size()) {
        if (arr.empty() || heights[index] >= heights[arr.back()]) {
            arr.push_back(index);
            index++;
        } else {
            ll last = arr.back();
            arr.pop_back();
            
            ll width;
            if(arr.empty())  width = index;
            else  width = index - arr.back() - 1;
            max_area = max(max_area, heights[last] * width);
        }
    }

    while (!arr.empty()) {
        ll last = arr.back();
        arr.pop_back();
        
        ll width;
        if(arr.empty())  width = index;
        else  width = index - arr.back() - 1;
        max_area = max(max_area, heights[last] * width);
    }

    return max_area;
}

int main() {
// write your code here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    vector<ll> height(n);
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        height[i] = x;
    }
    
    ll result = largestRectangleArea(height);
    cout << result;
    
    
	return 0;
}
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
using ll = long long;


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
    ll n; cin >> n;
    vector<ll> cake;
    for(ll i = 0; i < n; i++){
        ll x; cin >> x;
        cake.push_back(x);
    }
    
    ll result = largestRectangleArea(cake);
    cout << result;
    
    return 0;
}

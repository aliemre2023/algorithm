//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr;
    arr.reserve(n + 1);
    int x; cin >> x;
    arr.push_back(x);
    
    for(int i = 0; i < n; i++){
        int idx = (arr.size() - 1) / 2;
        if(arr.size() % 2){
            cout << arr[idx] << "\n";
        }
        else{
            cout << (arr[idx] + arr[idx+1]) / 2 << "\n";
        }

        cin >> x;
        /*
        int left = 0, right = arr.size();
        while(left < right){
            int mid = left + ((right - left) / 2);
            if (arr[mid] < x)
                left = mid + 1;
            else
                right = mid;
        }
        arr.insert(arr.begin() + left, x);
        */
        auto it = lower_bound(arr.begin(), arr.end(), x);
        arr.emplace(it, x);
    }

    return 0;
}

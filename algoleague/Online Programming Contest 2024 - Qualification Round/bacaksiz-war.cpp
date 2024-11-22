/*
 El Primos: 
 Ferhat Kunduracı (SchumacherFarad, ferhatkundurac), 
 Umut Özil (umut373), 
 Ali Emre Kaya (aliemre2023)
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
bool is_usable(vector<int>& positions, int k, int d) {
    int count = 1;
    int lastPosition = positions[0];

    for (int i = 1; i < positions.size(); i++) {
        if (positions[i] - lastPosition >= d) {
            count++;
            lastPosition = positions[i];
        }
        if (count == k) return true; 
    }

    return false;
}

int32_t main() {
    int n, k; cin >> n >> k;
    vector<int> positions(n);

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        positions[i] = x;
    }

    sort(positions.begin(), positions.end());
    int mini = 1; // leftest
    int maxi = positions.back() - positions[0]; // rightest
    int result = 0;
    
    while (mini <= maxi) { 
        // binary search
        int mid = mini + (maxi - mini) / 2;

        if (is_usable(positions, k, mid)) {
            result = mid; 
            mini = mid + 1; // ok
        } else {
            maxi = mid - 1; // too long
        }
    }
    cout << result;
    return 0;
}

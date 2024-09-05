#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; 
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n, k; 
        cin >> n >> k;
        vector<double> angles;
        
        for (int j = 0; j < n; j++) {
            double x, y; 
            cin >> x >> y;
            double z = sqrt(pow(x, 2) + pow(y, 2));
            double arcsin_val = asin(y / z);
            double val = (arcsin_val * 180.0) / 3.14159265;
            
            // Normalize the angle to be within [0, 360]
            if (x < 0) {
                val = 180 - val;
            } else if (x > 0 && y < 0) {
                val = 360 + val;
            }
            
            angles.push_back(val);
        }
        
        sort(angles.begin(), angles.end());
        
        double min_angle = DBL_MAX;
        
        for (int j = 0; j <= angles.size() - k; j++) {
            double interval = angles[j + k - 1] - angles[j];
            min_angle = min(min_angle, interval);
        }
        
        // Consider the circular nature of angles
        double circular_interval = 360 - (angles.back() - angles.front());
        min_angle = min(min_angle, circular_interval);
        
        cout << fixed << setprecision(2) << min_angle << "\n";
    }
    
    return 0;
}
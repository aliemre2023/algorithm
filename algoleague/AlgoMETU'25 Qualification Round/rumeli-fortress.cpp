#include <iostream>
#include <cmath>
#include <iomanip>
#define int long long
using namespace std;

class CircleLineSolver {
private:
    static long double getIntersectionLength(long double a, long double b, long double r) {

        long double perpDist = abs(b) / sqrtl(1.0L + a * a);
        if (perpDist > r) return 0.0L;
        

        long double aa = 1.0L + a * a;
        long double bb = 2.0L * a * b;
        long double cc = b * b - r * r;
        
        long double disc = bb * bb - 4.0L * aa * cc;
        if (disc <= 0.0L) return 0.0L;
        
        long double x1 = (-bb - sqrtl(disc)) / (2.0L * aa);
        long double x2 = (-bb + sqrtl(disc)) / (2.0L * aa);
        
    
        long double y1 = a * x1 + b;
        long double y2 = a * x2 + b;
        
        return sqrtl((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    }

public:
    static long double solve(long double a, long double b, long double l) {
        // Binary search, min rad
        long double left = 0.0L;
        long double right = hypotl(l, abs(b)) + 1.0L;  
        
        for (int iter = 0; iter < 100; iter++) { 
            long double mid = (left + right) / 2.0L;
            long double intersectLen = getIntersectionLength(a, b, mid);
            
            if (intersectLen >= l) {
                right = mid;
            } else {
                left = mid;
            }
        }
        
        return left;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        long double a, b, l;
        cin >> a >> b >> l;
        
        long double result = CircleLineSolver::solve(a, b, l);
        cout << fixed << setprecision(4) << result << "\n";
    }
    
    return 0;
}
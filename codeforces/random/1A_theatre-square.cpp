#include <iostream>
#include <cmath>

using namespace std;
#define int long long

int32_t main(){
    int n, m, a; cin >> n >> m >> a;

    int x = ceil((double)n / a);
    int y = ceil((double)m / a);
    //cout << "x: " << x << "\ny: " << y << "\nxy: " << x*y << "\n";

    cout << x * y;
    return 0;
}
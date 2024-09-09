#include <iostream>

using namespace std;

#define int long long

int32_t main(){
    int x, y, z;
    cin >> x >> y >> z;

    int per_x = x / z;
    int per_y = y / z;

    int total = (x + y) / z;
    int per = per_x + per_y;

    int exc = 0;
    if(per != total){
        exc = min(z - (x % z), z - (y % z));
    }

    cout << total << " " << exc;
    return 0;
}
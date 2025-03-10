#include <iostream>

using namespace std;
#define int long long

int32_t main(){
    int n; cin >> n;

    while(n--){
        int x, y; cin >> x >> y;

        int sqr = max(x, y) * max(x, y);

        if(max(x,y) % 2){
            sqr -= max(x, y)-1;
            if(x < y){
                sqr -= x;
                sqr += y;
            }
            else{
                //cout << "XXX1: " << sqr << "\n";
                sqr -= x;
                //cout << "XXX2: " << sqr << "\n";
                sqr += y;
                //cout << "XXX3: " << sqr << "\n";
            }
        }
        else{
            sqr -= max(x, y)-1;
            if(x < y){
                sqr -= y;
                sqr += x;
            }
            else{
                sqr += x;
                sqr -= y;
            }
        }

        cout << sqr << "\n";
    }

    return 0;
}
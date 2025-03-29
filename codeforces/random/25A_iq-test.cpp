#include <iostream>
#include <cmath>

using namespace std;
#define int long long

int32_t main(){
    int n; cin >> n;

    int first; cin >> first;
    int second; cin >> second;
    int third; cin >> third;

    if(first % 2 == 0 && second % 2 == 0 && third % 2 == 0){
        for(int i  = 3; i < n; i++){
            int x; cin >> x;
            if(x % 2 == 1){
                cout << i+1;
                break;
            }
        }
    }
    else if(first % 2 == 1 && second % 2 == 1 && third % 2 == 1){
        for(int i  = 3; i < n; i++){
            int x; cin >> x;
            if(x % 2 == 0){
                cout << i+1;
                break;
            }
        }
    }
    else {
        if(first % 2 == second % 2){
            cout << 3;
        }
        else if(second % 2 == third % 2){
            cout << 1;
        }
        else {
            cout << 2;
        }
    }

    return 0;
}
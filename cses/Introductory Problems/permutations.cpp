#include <iostream>
 
using namespace std;
#define int long long
 
int32_t main(){
    int n; cin >> n;
 
    if(n == 1){
        cout << "1";
        return 0;
    }
 
    if(n < 4){
        cout << "NO SOLUTION";
    }
    else{
        int curr = n;
        for(int i = n-1; 1 <= i; i-=2){
            cout << i << " ";
        }
        for(int i = n; 1 <= i; i-=2){
            cout << i << " ";
        }
    }
 
    return 0;
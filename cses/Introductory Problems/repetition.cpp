#include <iostream>

using namespace std;
#define int long long

int32_t main(){
    string s; cin >> s;

    char c = 'Q';
    int maxi = 0;
    int current = 0;
    for(int i = 0; i < s.size(); i++){
        if(c != s[i]){
            c = s[i];
            maxi = max(maxi, current);
            current = 1;
        }
        else{
            current += 1;
        }
    }
    maxi = max(maxi, current);

    cout << maxi;

    return 0;
}
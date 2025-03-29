// B. Lady Bug

#include <iostream>
#include <vector>

using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q; cin >> q;

    while(q--){
        int n; cin >> n;

        string arr1; cin >> arr1;
        string arr2; cin >> arr2;

        int arr1_even1 = 0;
        int arr1_odd1 = 0;
        for(int i = 0; i < n; i++){
            if(arr1[i] == '1'){
                if(i % 2 == 1) arr1_odd1++;
                else arr1_even1++; 
            }
            if(arr2[i] == '0'){
                if(i % 2 == 0) arr1_odd1--;
                else arr1_even1--; 
            }
        }

        if(arr1_even1 > 0 || arr1_odd1 > 0) cout << "no" << "\n";
        else cout << "yes" << "\n";
    }

    return 0;
}
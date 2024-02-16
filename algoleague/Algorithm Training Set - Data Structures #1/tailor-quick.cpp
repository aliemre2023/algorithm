//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!


#include <vector>
#include <iostream>

using namespace std;
#define int long long

int32_t main() {
// write your code here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    
    
    int n; cin >> n;
    
    vector<int> arr;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        arr.push_back(x);
    }
    for(int i = 0; i < n; i++){
        arr.push_back(arr[i]);
    }

    vector<int> res;
    
    for(int i = 0; i < n; i++){
        bool is_big = true;
        for(int j = i+1; j < n+i+1; j++){
            if(arr[i] < arr[j]){
                is_big = false;
                res.push_back(arr[j]);
                break;
            }
        }
        if(is_big){
            res.push_back(-1);
        }
    }
    
    
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    
    
	return 0;
}

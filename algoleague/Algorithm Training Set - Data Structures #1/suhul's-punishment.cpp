//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <set>
#include <map>
#include <iostream>

using namespace std;
#define int long long

int32_t main() {
// write your code here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    set<int> arr;
    map<int,int> count_holder;
    
    
    
    int n, m ; cin >> n >> m;
    
    if(m == 0){
        int zero_counter = 0;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            
            if(x == 0){
                zero_counter++;
            }
        }
        int res = 0;
        for(int i = 0; i < zero_counter; i++){
            res += n - 1 - i;
        }
        cout << res;
        return 0;
    }
    ///////////// 0
    
    
    
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x == 0){
            arr.insert(x);
            count_holder[x]++;
            continue;
        }
        if(m % x != 0) continue;
        arr.insert(x);
        count_holder[x]++;
    }
    
    int counter = 0;
    
    for (int real : arr) {
        if (real != 0){
            int divider = m / real;
            if (arr.count(divider)) {
                auto it1 = count_holder.find(real);
                auto it2 = count_holder.find(divider);
                if(it1 != count_holder.end() && it2 != count_holder.end()){
                    if(real != divider){
                        counter += count_holder[real] * count_holder[divider];
                    }
                    else{
                        counter += count_holder[real] * (count_holder[divider]-1);
                    }
                    
                }
            }
        }
    }
    cout << counter / 2;
    
	return 0;
}

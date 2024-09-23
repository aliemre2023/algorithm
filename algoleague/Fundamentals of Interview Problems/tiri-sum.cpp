//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
// write your code here
    
    int n; cin >> n;
    vector<int> arr;
    for(int i = 0 ;i <n; i++){
        int x; cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());
    int t; cin >> t;

    for(int i = 0; i < n; i++){
        int target = -arr[i] + t;
        int front = 0;
        int back = arr.size()-1;
        
        while(back > front){
            int sum = arr[front] + arr[back];
            
            if(sum < target){
                front++;
            }
            else if(sum > target){
                back--;
            }
            else{
                if(i != front || i != back){
                    cout << "YES";
                    return 0;
                }
            }
        }
    }
    cout << "NO";
    
        
	return 0;
}

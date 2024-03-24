#include <bits/stdc++.h>

using namespace std;

int main() {
// write your code here
    int num_c; cin >> num_c;
    int query_c; cin >> query_c;
    
    int prefix = 0;
    vector<int> nums(num_c);
    for(int i=0; i<num_c; i++){
        int num; cin >> num;
        prefix += num;
        nums[i] = prefix;
    }
    
    int count = 0;
    while(query_c > count){
        count++;
        long long sum = 0;
        
        int i1; cin >> i1;
        int i2; cin >> i2;
        
        sum = nums[i2-1] - nums[i1-2];
        cout << sum << endl;
    }
    
	return 0;
}

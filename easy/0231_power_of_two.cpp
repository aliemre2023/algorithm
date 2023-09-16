// Time Complexity = O(log(n))
// Space Complexity = O(1)

class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long base = 1;
        while(base <= n){
            if(base == n) return true;
            base *= 2;
        }
        return false;
    }
};
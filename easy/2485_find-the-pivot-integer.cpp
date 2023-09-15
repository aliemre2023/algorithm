// Time Complexity = O(n)
// Space Complexity = O(1)

class Solution {
public:
    int pivotInteger(int n) {
        int sum = 0;
        int wanted = ((n) * (n+1)) / 2;
        if(n == 1) return 1;
        for(int i = 1; i <= n; i++){
            sum += i;
            int right = wanted - sum + i;
            if(sum == right) return i;
        }
        return -1;
    }
};
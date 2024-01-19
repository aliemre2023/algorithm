// Time Complexity = O(n)
// Space Complexity = O(1)
// Question Link = https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
    int climbStairs(int n) {
        int n1=0, n2=1, temp;
        for(int i = 0; i < n; i++){
            temp = n2;
            n2 = n1 + n2;
            n1 = temp;
        }
        return n2;
    }
};
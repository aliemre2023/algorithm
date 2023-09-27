// Time Compleixty = O(x * log10(n))
// Space Compleixty = O(1)
// Question Link = https://leetcode.com/problems/happy-number/

class Solution {
public:
    int sum_find(int n){
        int sum = 0;
        int temp;
        while(n){
            temp = n % 10;
            sum += temp * temp;
            n = n / 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int fast = n;
        fast = sum_find(fast);
        while(n != fast){
            n = sum_find(n);
            fast = sum_find(fast);
            fast = sum_find(fast);
        }
        if(n == 1) return true;
        else return false;
    }
};
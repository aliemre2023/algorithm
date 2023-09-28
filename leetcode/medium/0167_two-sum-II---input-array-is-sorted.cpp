// Time Complexity = O(n)
// Space Complexity = O(1)
//  Question Link = https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int ptr1 = 0;
        int ptr2 = numbers.size()-1;

        while(numbers[ptr1] + numbers[ptr2] != target){
            if(numbers[ptr1] + numbers[ptr2] < target) ptr1++;
            else ptr2--;
        }

        return {ptr1+1, ptr2+1};     
    }
};
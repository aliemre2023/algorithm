// Time Complexity = O(digits.size())
// Space Complexity = O(1)

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size() - 1; 0 <= i; i--){
            if(digits[i] != 9){
                digits[i]++;
                break;
            }
            else{
                digits[i] = 0;           
            }
        }
        if(digits[0] == 0){
            digits[0] = 1;
            digits.push_back(0);
        }
        return digits;
    }
};
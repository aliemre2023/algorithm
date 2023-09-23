// Time Complexity = O(1)
// Sapce Complexity = O(1)

class Solution {
public:
    bool canWinNim(int n) {
        if(n % 4 == 0){
            return false;
        }
        else{
            return true;
        }
    }
};
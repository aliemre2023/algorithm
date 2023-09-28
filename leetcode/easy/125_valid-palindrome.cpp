// Time Comlexity = O(n)
// Space Complexity = O(1)
// Question Link

class Solution {
public:
    bool isPalindrome(string s) {

        int front = 0;
        int back = s.size()-1;

        while(back > front){
            while(isalnum(s[front]) == false && front < back) front++;
            while(isalnum(s[back]) == false && front < back) back--;

            if(toupper(s[front]) != toupper(s[back])) return false;
            back--;
            front++;
        }
        return true;
    }
};
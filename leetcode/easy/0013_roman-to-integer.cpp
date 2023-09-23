// Time Complexity = 0(n)
// Space Complexity = O(1)
// Question Link = https://leetcode.com/problems/roman-to-integer/

class Solution {
public:
    int romanToInt(string s) {
        int i = 0;
        int sum = 0;
        for(; i < s.size() - 1; i++){
            if(s[i] == 'M'){
                sum += 1000;
            }
            else if(s[i] == 'C' && s[i+1] == 'M'){
                sum += 900;
                i++;
            }
            else if(s[i] == 'D'){
                sum += 500;
            }
            else if(s[i] == 'C' && s[i+1] == 'D'){
                sum += 400;
                i++;
            }
            else if(s[i] == 'C'){
                sum += 100;
            }
            else if(s[i] == 'X' && s[i+1] == 'C'){
                sum += 90;
                i++;
            }
            else if(s[i] == 'L'){
                sum += 50;
            }
            else if(s[i] == 'X' && s[i+1] == 'L'){
                sum += 40;
                i++;
            }
            else if(s[i] == 'X'){
                sum += 10;
            }
            else if(s[i] == 'I' && s[i+1] == 'X'){
                sum += 9;
                i++;
            }
            else if(s[i] == 'V'){
                sum += 5;
            }
            else if(s[i] == 'I' && s[i+1] == 'V'){
                sum += 4;
                i++;
            }
            else{
                sum += 1;
            }
        }
        if(i == s.size() - 1){
            if(s[i] == 'M'){
                sum += 1000;
            }
            else if(s[i] == 'D'){
                sum += 500;
            }
            else if(s[i] == 'C'){
                sum += 100;
            }
            else if(s[i] == 'L'){
                sum += 50;
            }
            else if(s[i] == 'X'){
                sum += 10;
            }
            else if(s[i] == 'V'){
                sum += 5;
            }
            else{
                sum += 1;
            }
        }
        return sum;
    }
};
// Time Complexity = O(n)
// Space Complexity = O(n)
// Question Link = https://leetcode.com/problems/add-binary/

class Solution {
public:
    string addBinary(string a, string b) {

        int Asize = a.size()-1;
        int Bsize = b.size()-1;

        string reverseRes;
        int second = 0;

        while(Asize >= 0 && Bsize >= 0){
            if(a[Asize] == '1' && b[Bsize] == '1'){
                if(second){
                    reverseRes.push_back('1');
                    second = 1;
                }
                else{
                    reverseRes.push_back('0');
                    second = 1;
                }
            }
            else if((a[Asize] == '1' && b[Bsize] == '0') || (a[Asize] == '0' && b[Bsize] == '1')){
                if(second){
                    reverseRes.push_back('0');
                    second = 1;
                }
                else{
                    reverseRes.push_back('1');
                }
            }
            else{
                if(second){
                    reverseRes.push_back('1');
                    second = 0;
                }
                else{
                    reverseRes.push_back('0');
                }
            }
            Asize--;
            Bsize--;
        }

        while(Asize >= 0){
            if(a[Asize] == '1'){
                if(second){
                    reverseRes.push_back('0');
                    second = 1;
                }
                else{
                    reverseRes.push_back('1');
                }
            }
            else{
                if(second){
                    reverseRes.push_back('1');
                    second = 0;
                }
                else{
                    reverseRes.push_back('0');
                }     
            }
            Asize--;
        }
        while(Bsize >= 0){
            if(b[Bsize] == '1'){
                if(second){
                    reverseRes.push_back('0');
                    second = 1;
                }
                else{
                    reverseRes.push_back('1');
                }
            }
            else{
                if(second){
                    reverseRes.push_back('1');
                    second = 0;
                }
                else{
                    reverseRes.push_back('0');
                }
            }
            Bsize--;
        }

        if(second){
            reverseRes.push_back('1');
        }

        reverse(reverseRes.begin(), reverseRes.end());
        return reverseRes;
    }
};
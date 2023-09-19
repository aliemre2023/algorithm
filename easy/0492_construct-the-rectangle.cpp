// Time Complexity = O(sqrt(n))
// Space Complexity = O(1)
// Question Link = https://leetcode.com/problems/construct-the-rectangle

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int sq = sqrt(area);
        int temp = area / sq;
        while(area % sq != 0){
            sq -= 1;
            temp = area / sq;
        }
        return {temp, sq};
    }
};
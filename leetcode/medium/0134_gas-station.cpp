// Time Complexity = O(n)
// Space Complexity = O(1)
// Question Link = https://leetcode.com/problems/gas-station/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        int sum2 = 0;
        int idx = 0;
        for(int i = 0; i < gas.size(); i++){
            sum += gas[i] - cost[i];
            gas[i] = (gas[i] - cost[i]);

            sum2 += gas[i];
            if(sum2 < 0){
                idx = i+1;
                sum2 = 0;
            } 
        }
        if(sum < 0){
            return -1;
        }  
        return idx;
    }
};
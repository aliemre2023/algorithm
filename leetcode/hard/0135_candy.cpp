class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies_counter(n, 1);

        // left to right
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i - 1]){
                candies_counter[i] = candies_counter[i - 1] + 1;
            }
        }

        // right to left
        for(int i = n - 2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1]){
                candies_counter[i] = max(candies_counter[i], candies_counter[i + 1] + 1);
            }
        }

        long total_candies = 0;
        for(int i = 0; i < n; i++){
            total_candies += candies_counter[i];
        }
        return total_candies;
    }
};
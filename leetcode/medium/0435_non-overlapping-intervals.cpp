bool compare_by_second(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
}

class Solution {
public:

    int max_event_count(vector<vector<int>> schedule){
        // sort according to finish times
        sort(schedule.begin(), schedule.end(), compare_by_second);

        int count = 0;
        int last_end = -5*1e4 - 1;

        for(int i = 0; i < schedule.size(); i++){
            if(schedule[i][0] < last_end){
                continue;
            }

            last_end = schedule[i][1];
            count++;
            //cout << "{" << schedule[i][0] << "," << schedule[i][1] << "}\n";

        }

        return count;
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count = max_event_count(intervals);
        return intervals.size() - count;
    }
};
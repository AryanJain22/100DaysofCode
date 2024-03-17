class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int pushed = 0;
        for(int i=0;i<intervals.size();i++){
            int intervalStart = intervals[i][0];
            int intervalEnd = intervals[i][1];
            //2 ways to overlap
            if ((newInterval[0] >= intervalStart && newInterval[0] <= intervalEnd) || (newInterval[0] <= intervalStart && newInterval[1] >= intervalStart)){
                newInterval[0] = min(intervalStart,newInterval[0]);
                newInterval[1] = max(intervalEnd,newInterval[1]);
            }
            else if (intervalStart > newInterval[0] && intervalEnd > newInterval[1]){
                if (pushed == 0){
                    ans.push_back({newInterval});
                    pushed = 1;
                }
                ans.push_back(intervals[i]);
            }  
            else if (intervalStart < newInterval[0] && intervalEnd < newInterval[1])
                ans.push_back(intervals[i]);
        }
        if (pushed == 0)
            ans.push_back(newInterval);
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
            return a[0] < b[0];
        });

        vector<vector<int>> ans;
        int n = intervals.size();
        for(int i=0;i<n;i++){
            if(i==0 || ans.back()[1] < intervals[i][0])
                ans.push_back(intervals[i]);
            else{
                auto it = ans.back();
                ans.pop_back();
                ans.push_back({it[0], max(intervals[i][1],it[1])});
            }
        }
        return ans;
    }
};

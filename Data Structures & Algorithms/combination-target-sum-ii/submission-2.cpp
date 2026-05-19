class Solution {
    set<vector<int>> st;
    void solve(vector<int> &nums, int target, int index, vector<int> &tmp, vector<vector<int>> &ans){
        if(target == 0){
            if(st.find(tmp) == st.end()){
                ans.push_back(tmp);
                st.insert(tmp);
            }
            return;
        }
        if(target < 0 || index >= nums.size())
            return;
        tmp.push_back(nums[index]);
        solve(nums, target-nums[index], index+1, tmp, ans);
        tmp.pop_back();
        while(index+1 < nums.size() && nums[index] == nums[index+1])
            index++;
        solve(nums, target, index+1, tmp, ans);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0, tmp, ans);
        return ans;
    }
};

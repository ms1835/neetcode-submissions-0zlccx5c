class Solution {
    void solve(vector<int> &nums, int target, int index, vector<vector<int>> &ans,
     vector<int> &tmp){
        if(target < 0) return;
        if(target == 0){
            ans.push_back(tmp);    
            return;
        }
        if(index >= nums.size()) return;
        tmp.push_back(nums[index]);
        solve(nums, target-nums[index], index, ans, tmp);
        tmp.pop_back();
        solve(nums, target, index+1, ans, tmp);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> tmp;
        solve(nums, target, 0, ans, tmp);
        return ans;
    }
};

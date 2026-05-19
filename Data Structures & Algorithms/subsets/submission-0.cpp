class Solution {
    void solve(vector<int> &nums, vector<int> &tmp, vector<vector<int>> &ans, int index){
        if(index == nums.size()){
            ans.push_back(tmp);
            return;
        }
        tmp.push_back(nums[index]);
        solve(nums, tmp, ans, index+1);
        tmp.pop_back();
        solve(nums, tmp, ans, index+1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        solve(nums, tmp, ans, 0);
        return ans;
    }
};

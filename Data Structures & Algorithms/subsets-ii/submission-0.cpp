class Solution {
    void solve(vector<int> &nums, vector<vector<int>> &ans, vector<int> &tmp, int index){
        if(index == nums.size()){
            ans.push_back(tmp);
            return;
        }
        tmp.push_back(nums[index]);
        solve(nums, ans, tmp, index+1);
        tmp.pop_back();
        while(index+1 < nums.size() && nums[index] == nums[index+1])
            index++;
        solve(nums, ans, tmp, index+1);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        solve(nums, ans, tmp, 0);
        return ans;
    }
};

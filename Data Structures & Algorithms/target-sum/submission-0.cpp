class Solution {
    int solve(vector<int> &nums, int index, int curr, int totalSum, int target, vector<vector<int>> &dp) {
        if(index == nums.size()) return curr == target;
        if(dp[index][curr+totalSum] != -1) return dp[index][curr+totalSum];
        int add = solve(nums, index+1, curr+nums[index], totalSum, target, dp);
        int subtract = solve(nums, index+1, curr-nums[index], totalSum, target, dp);
        return dp[index][totalSum+curr] = add + subtract;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n, vector<int>(2*totalSum+1, -1));
        return solve(nums, 0, 0, totalSum, target, dp);
    }
};

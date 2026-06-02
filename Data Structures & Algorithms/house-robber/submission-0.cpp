class Solution {
    int solve(vector<int> &nums, int index, vector<int> &dp) {
        if(index < 0) return 0;
        if(dp[index] != -1)
            return dp[index];

        int notPick = solve(nums, index-1, dp);
        int pick = nums[index] + solve(nums, index-2, dp);
        return dp[index] = max(pick, notPick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(nums, n-1, dp);
    }
};

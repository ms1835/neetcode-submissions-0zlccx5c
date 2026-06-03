class Solution {
    int solve(vector<int> &nums, int index, vector<int> &dp) {
        if(index == 0 || index == 1)
            return nums[index];
        if(dp[index] != -1)
            return dp[index];
        return dp[index] = nums[index] + min(solve(nums, index-1, dp), solve(nums, index-2, dp));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        return min(solve(cost, n-1, dp), solve(cost, n-2, dp));
    }
};

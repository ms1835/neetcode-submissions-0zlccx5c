class Solution {
    bool solve(vector<int> &nums, int index, int currSum, int totalSum, vector<vector<int>> &dp) {
        if(index < 0) return false;
        if(currSum > totalSum) return false;
        if(index == 0) return currSum == totalSum;
        if(dp[index][currSum] != -1) return dp[index][currSum];
        int pick = solve(nums, index-1, currSum+nums[index], totalSum-nums[index], dp);
        int notPick = solve(nums, index-1, currSum, totalSum, dp);
        return dp[index][currSum] = pick || notPick;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n, vector<int>(totalSum, -1));
        return solve(nums, n-1, 0, totalSum, dp);
    }
};

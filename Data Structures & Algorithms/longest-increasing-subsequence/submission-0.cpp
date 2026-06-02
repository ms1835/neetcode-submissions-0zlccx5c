class Solution {
    int solve(vector<int> &nums, int index, int prevIndex, vector<vector<int>> &dp) {
        if(index < 0){
            return 0;
        }
        if(dp[index][prevIndex+1] != -1)
            return dp[index][prevIndex+1];
        int notPick = solve(nums, index-1, prevIndex, dp);
        int pick = 0;
        if(prevIndex == -1 || nums[index] < nums[prevIndex]) 
            pick = 1 + solve(nums, index-1, index, dp);
        return dp[index][prevIndex+1] =  max(pick, notPick);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(nums, n-1, -1, dp);
    }
};

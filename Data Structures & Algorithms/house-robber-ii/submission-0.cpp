class Solution {
    int solve(vector<int> &nums, int index, vector<int> &dp) {
        if(index < 0) return 0;
        if(dp[index] != -1) return dp[index];
        int notPick = solve(nums, index-1, dp);
        int pick = nums[index] + solve(nums, index-2, dp);
        return dp[index] = max(pick, notPick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> copy1(nums.begin()+1, nums.end());
        vector<int> copy2(nums.begin(), nums.end()-1);

        vector<int> dp(n, -1);
        int res1 = solve(copy1, n-2, dp);
        fill(dp.begin(), dp.end(), -1);
        int res2 = solve(copy2, n-2, dp);
        return max(res1, res2);
    }
};

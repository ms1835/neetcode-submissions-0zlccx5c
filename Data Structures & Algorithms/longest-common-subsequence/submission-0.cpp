class Solution {
    int solve(string str1, string str2, int i, int j, vector<vector<int>> &dp) {
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(str1[i] == str2[j])
            return dp[i][j] = 1 + solve(str1, str2, i-1, j-1, dp);
        else
            return dp[i][j] = max(solve(str1, str2, i, j-1, dp), solve(str1, str2, i-1, j, dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length(), len2 = text2.length();
        vector<vector<int>> dp(len1, vector<int>(len2, -1));
        return solve(text1, text2, len1-1, len2-1, dp);
    }
};

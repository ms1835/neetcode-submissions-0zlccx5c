class Solution {
    int solve(string str1, int i, string str2, int j, vector<vector<int>> &dp) {
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(str1[i] == str2[j])
            return dp[i][j] = solve(str1, i-1, str2, j-1, dp);
        else{
            int insert = 1 + solve(str1,i,str2,j-1,dp);
            int del = 1 + solve(str1, i-1, str2, j, dp);
            int replace = 1 + solve(str1, i-1, str2, j-1, dp);
            return dp[i][j] = min(insert, min(del, replace));
        }
    }
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.length(), n2 = word2.length();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return solve(word1, n1-1, word2, n2-1, dp);
    }
};

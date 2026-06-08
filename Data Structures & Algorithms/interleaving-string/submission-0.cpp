class Solution {
    bool solve(string &s1, string &s2, string &s3, int i, int j, vector<vector<int>> &dp) {
        if(i == s1.length() && j == s2.length() && i+j == s3.length())
            return true;
        if(i+j >= s3.length()) return false;

        if(dp[i][j] != -1) return dp[i][j];

        bool result = false;
        if(s1[i] == s3[i+j])
            result = solve(s1,s2,s3,i+1,j, dp);
        if(result) return dp[i][j] = true;
        if(s2[j] == s3[i+j])
            result =  solve(s1,s2,s3,i,j+1, dp);
        return dp[i][j] = result;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();
        if(n+m != s3.length()) return false;

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        return solve(s1, s2, s3, 0, 0, dp);
    }
};

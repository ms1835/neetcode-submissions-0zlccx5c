class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int count = 0;
        for(int i=n-1;i>=0;i--){
            for(int j=i; j< n;j++) {
                if(i == j) 
                    dp[i][j] = 1;
                else if(s[i] == s[j] && j-i<2)
                    dp[i][j] = 1;
                else if(s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1];
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(dp[i][j])    count++;
            }
        }
        return count;
    }
};

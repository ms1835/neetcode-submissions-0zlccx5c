class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int left=0, maxf = 0, ans = 0;
        int n = s.length();

        for(int right = 0;right<n;right++){
            mp[s[right]]++;
            maxf = max(maxf, mp[s[right]]);

            while(right-left+1 - maxf > k){
                mp[s[left]]--;
                left++;
            }
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};

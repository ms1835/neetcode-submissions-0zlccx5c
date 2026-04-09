class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int len = strs.size();
        unordered_map<string, vector<string>> mp;
        string tmp;

        for(int i=0;i<len;i++) {
            tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if(mp.find(tmp) != mp.end()){
                mp[tmp].push_back(strs[i]);
            }
            else{
                mp[tmp] = {strs[i]};
            }
        }
        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};

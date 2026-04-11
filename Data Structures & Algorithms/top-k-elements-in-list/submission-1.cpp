class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        priority_queue<pair<int, int>, 
    vector<pair<int, int>>, greater<pair<int, int>>> q;
        vector<int> ans;

        for (auto x: nums){
            mp[x]++;
        }
        for(auto it: mp){
            q.push({it.second, it.first});
            if(q.size() > k)
                q.pop();
        }
        for(int i=0;i<k;i++){
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};

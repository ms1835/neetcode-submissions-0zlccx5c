class Solution {
    unordered_map<string, int> mp;
    int solve(int index, bool buying, vector<int> &prices){
        if(index >= prices.size())
            return 0;

        string key = to_string(index) + "-" + to_string(buying);
        if(mp.find(key) != mp.end())
            return mp[key];
        int cooldown = solve(index+1, buying, prices);
        if(buying){
            int buy = solve(index+1, false, prices) - prices[index];
            mp[key] = max(buy, cooldown);
        }
        else{
            int sell = solve(index+2, true, prices) + prices[index];
            mp[key] = max(sell, cooldown);
        }
        return mp[key];
    }
public:
    int maxProfit(vector<int>& prices) {
        return solve(0, true, prices);
    }
};

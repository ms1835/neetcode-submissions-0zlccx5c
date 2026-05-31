class Solution {
public:
    unordered_map<int,int> mp;
    int solve(vector<int> &coins, int amount){
        if(amount == 0)
            return 0;
        if(mp.find(amount) !=mp.end())
            return mp[amount];
        int res = INT_MAX;
        for(int coin: coins) {
            if(amount -coin >= 0){
                int result = solve(coins, amount-coin);
                if(result != INT_MAX)
                    res = min(res, 1+ result);
            }
        }
        return mp[amount] = res;
    }

    int coinChange(vector<int>& coins, int amount) {
        int ans = solve(coins, amount);
        return ans == INT_MAX ? -1 : ans;
    }
};

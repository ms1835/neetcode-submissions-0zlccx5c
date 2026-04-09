class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0, cost = prices[0];
        for(int i=1;i<n;i++) {
            if(prices[i] > cost) {
                maxProfit = max(maxProfit, prices[i] - cost);
            }
            else
                cost = prices[i];
        }
        return maxProfit;
    }
};

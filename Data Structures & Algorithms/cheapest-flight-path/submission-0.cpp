class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n, 1e9);
        prices[src] = 0;

        for(int i=0;i<=k;i++){
            vector<int> tmpPrices = prices;
            for(auto &flight: flights){
                int u = flight[0];
                int v = flight[1];
                int wt = flight[2];

                if(prices[u] + wt < tmpPrices[v])
                    tmpPrices[v] = prices[u] + wt;
            }
            prices = tmpPrices;
        }
        return prices[dst] != 1e9 ? prices[dst] : -1;
    }
};

class Solution {
    int helper(vector<int> piles, int k){
        int res = 0;
        for(int i=0;i<piles.size();i++){
            res += ceil(1.0*piles[i]/k);
        }
        return res;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        auto it = max_element(piles.begin(), piles.end());
        int maxValue = *it;
        int ans = maxValue, count;

        int low = 1, high = maxValue, mid;
        while(low <= high){
            mid = low + (high-low)/2;
            count = helper(piles, mid);
            if(count > h)
                low = mid + 1;
            else{
                high = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxAtIndex = nums[0];
        int res = nums[0];

        for(int i=1;i<nums.size();i++){
            maxAtIndex = max(maxAtIndex+nums[i], nums[i]);
            res = max(res, maxAtIndex);
        }
        return res;
    }
};

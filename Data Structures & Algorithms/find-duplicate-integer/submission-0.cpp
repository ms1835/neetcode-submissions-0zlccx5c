class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(), idx;
        for(int i=0;i<n;i++){
            idx = abs(nums[i])-1;
            if(nums[idx] < 0)
                return abs(nums[i]);
            nums[idx] = -nums[idx];
        }
        return -1;
    }
};

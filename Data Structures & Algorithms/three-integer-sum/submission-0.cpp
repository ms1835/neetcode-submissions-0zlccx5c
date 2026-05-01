class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size(), left, right, curr;
        for(int i=0;i<n-1;i++){
            if(i>0 && nums[i] == nums[i-1])
                continue;
            left = i+1;
            right = n-1;
            while(left < right){
                curr = nums[i] + nums[left] + nums[right];
                if(curr == 0){
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while(left < right && nums[left] == nums[left-1])
                        left++;
                }
                else if(curr > 0)
                    right--;
                else 
                    left++;
            }
        }
        return ans;
    }
};

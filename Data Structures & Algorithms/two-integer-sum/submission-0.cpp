class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        int rem;
        for(int i=0;i<nums.size();i++){
            rem = target-nums[i];
            if(mp.find(rem) != mp.end())
                return {mp[rem], i};
            mp.insert({nums[i], i});
        }
        return {-1,-1};
    }
};

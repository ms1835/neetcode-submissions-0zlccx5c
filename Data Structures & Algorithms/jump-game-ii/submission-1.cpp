class Solution {
    int solve(vector<int> &nums, int index, unordered_map<int,int> &mp){
        if(index ==nums.size()-1)
            return 0;
        if(nums[index] == 0)
            return 1000000;
        if(mp.find(index) != mp.end())
            return mp[index];

        int res = 1000000;
        int end = min((int)nums.size(), 1+nums[index]+index);
        for(int j=index+1;j<end;j++){
            res = min(res, 1+solve(nums, j, mp));
        }
        mp[index] = res;
        return res;
    }
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        return solve(nums, 0, mp);


    }
};

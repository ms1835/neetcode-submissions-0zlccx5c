class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x = 0, y = 0;
        for(auto el: nums)
            x ^= el;
        for(int i=0;i<=nums.size();i++)
            y ^= i;
        return x^y;
    }
};

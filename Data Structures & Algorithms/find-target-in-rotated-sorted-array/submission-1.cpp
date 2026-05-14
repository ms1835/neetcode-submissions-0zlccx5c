class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1, mid;

        while(low <= high) {
            mid = low + (high - low)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] >= nums[low]){
                if(target > nums[mid] || target < nums[low])
                    low = mid+1;
                else
                    high = mid-1;
            }
            else{
                if(target < nums[mid] || nums[high] < target)
                    high = mid-1;
                else
                    low = mid+1;
            }
        }
        return -1;
    }
};

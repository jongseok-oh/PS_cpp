class Solution {
    int lowerBound(vector<int>& nums, int target){
        int n = nums.size();
        int low = -1, high = n;

        while(low + 1 < high){
            int mid = (low + high)>>1;
            if(nums[mid] >= target) high = mid;
            else low = mid;
        }

        if(high == n || nums[high] != target) return -1;
        return high;
    }

    int upperBound(vector<int>& nums, int target){
        int n = nums.size();
        int low = -1, high = n;

        while(low + 1 < high){
            int mid = (low + high)>>1;
            if(nums[mid] > target) high = mid;
            else low = mid;
        }
        
        return high - 1;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       int lb = lowerBound(nums, target);

       if(lb == -1) return {-1,-1};

       return {lb, upperBound(nums, target)};
    }
};
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int left = 0, right = n;

        // pivot search
        while(left + 1 < right){
            int mid = (left + right) >> 1;

            if(nums[mid] >= nums[0]) left = mid;
            else right = mid;
        }

        int pivot = left;

        if(target >= nums[0]) left = -1, right = pivot + 1;
        else left = pivot, right = n;

        while(left + 1 < right){
            int mid = (left + right) >> 1;
            if(nums[mid] == target) return mid;

            if(nums[mid] >= target) right = mid;
            else left = mid;
        }
        return -1;
    }
};
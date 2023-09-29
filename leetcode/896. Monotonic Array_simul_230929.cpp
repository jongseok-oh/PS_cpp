class Solution {
    bool isMonotoneIncrease(vector<int>& nums){
        for(int i = 1; i<nums.size(); ++i)
            if(nums[i-1] > nums[i]) return false;
        
        return true;
    }

    bool isMonotoneDecrease(vector<int>& nums){
        for(int i = 1; i<nums.size(); ++i)
            if(nums[i-1] < nums[i]) return false;
        
        return true;
    }
public:
    bool isMonotonic(vector<int>& nums) {
        return isMonotoneIncrease(nums) || isMonotoneDecrease(nums);
    }
};
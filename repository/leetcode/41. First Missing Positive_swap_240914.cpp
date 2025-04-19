class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i<n; ++i){
            int val = nums[i];
            while(val > 0 && val <=n && nums[val-1] != val && i + 1 != val){
                swap(nums[i], nums[val-1]);
                val = nums[i];
            }
        }
        for(int i = 0; i<n; ++i){
            if(i + 1 != nums[i]) return i+1;
        }
        return n + 1;
    }
};
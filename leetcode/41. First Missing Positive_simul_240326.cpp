class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        nums.push_back(0);
        int n = nums.size();
        for(int i = 0; i<n; ++i){
            int x = nums[i];
            while(x>=0 && x<n && x != nums[x]){
                swap(nums[i], nums[x]);
                x = nums[i];
            }
        }
        for(int i = 1; i<n; ++i){
            if(nums[i] != i) return i;
        }
        return n;
    }
};
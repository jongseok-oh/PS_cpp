class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        for(int start = 0; start<n; ++start){
            bool invalid = false;
            for(int i = 0; i<n-1; ++i){
                if(nums[(start + i)%n] > nums[(start + i + 1)%n]){
                    invalid = true;
                    break;
                }
            }
            if(!invalid) return true;
        }
        return false;
    }
};
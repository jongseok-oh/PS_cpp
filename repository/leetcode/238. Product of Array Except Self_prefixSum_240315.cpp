class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n);
        
        int prefix = 1;
        for(int i = 0; i<n; ++i){
            ret[i] = prefix;
            prefix *= nums[i];
        }

        int sufix = 1;
        for(int i = n-1; i>=0; --i){
            ret[i] *= sufix;
            sufix *= nums[i];
        }

        return ret;
    }
};
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> modIdx;
        int prefixSum = nums[0] % k;
        modIdx[prefixSum] = 0;
        for(int i = 1; i<nums.size(); ++i){
            int num = nums[i];
            prefixSum = (num + prefixSum) % k;
            if(prefixSum == 0) return true;

            if(modIdx.count(prefixSum)){
                if(i - modIdx[prefixSum] > 1) return true;
            }else modIdx[prefixSum] = i;
        }
        return false;
    }
};
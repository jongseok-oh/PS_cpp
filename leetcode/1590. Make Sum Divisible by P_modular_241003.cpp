class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = 0;
        for(int num : nums){
            sum += num;
        }
        if(sum < p) return -1;
        
        int modSum = sum % p;
        if(modSum == 0) return 0;

        unordered_map<int, int> modIdx;
        modIdx[0] = -1;
        
        int n = nums.size(), tModSum = 0, ret = n;
        for(int i = 0; i<n; ++i){
            int num = nums[i];

            tModSum = (tModSum + num) % p;
            int diff = (tModSum - modSum + p) % p;
            if(modIdx.count(diff)){
                ret = min(ret, i - modIdx[diff]);
            }
            modIdx[tModSum] = i;
        }

        return (ret == n?-1:ret);
    }
};
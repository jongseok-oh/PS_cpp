class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> cnt;
        int ret = 0, n = nums.size();
        
        for(int i = 0, j = 0; j<n; ++j){
            if(++cnt[nums[j]]>k){
                while(nums[i] != nums[j])
                    --cnt[nums[i++]];
                --cnt[nums[i++]];
            }
            ret = max(ret, j-i + 1);
        }

        return ret;
    }
};
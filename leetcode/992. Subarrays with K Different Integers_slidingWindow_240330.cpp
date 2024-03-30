class Solution {
    int getSubCnt(vector<int>& nums, int k){
        unordered_map<int,int> cnt;

        int ret = 0, n = nums.size();
        for(int i = 0, j = 0; j<n; ++j){
            cnt[nums[j]]++;
            
            while(i<n && cnt.size() > k){
                if(--cnt[nums[i]] == 0) cnt.erase(nums[i]);
                ++i;
            }
            ret += j - i + 1;
        }
        return ret;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return getSubCnt(nums, k) - getSubCnt(nums, k-1);
    }
};
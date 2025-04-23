class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int distinctCnt = 0;
        bitset<2001> visit;
        for(int num : nums){
            if(visit[num]) continue;
            visit[num] = 1;
            ++distinctCnt;
        }

        int ret = 0;
        unordered_map<int, int> cnt;
        for(int i = 0, j = 0, n = nums.size(); i<n; ++i){
            while(j < n && cnt.size() < distinctCnt){
                ++cnt[nums[j++]];
            }
            if(cnt.size() == distinctCnt){
                ret += n - j + 1;
            }
            if(--cnt[nums[i]] == 0){
                cnt.erase(nums[i]);
            }
        }

        return ret;
    }
};
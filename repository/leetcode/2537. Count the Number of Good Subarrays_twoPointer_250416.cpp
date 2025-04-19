class Solution {
    using ll = long long;
public:
    ll countGood(vector<int>& nums, int k) {
        ll ret = 0;
        unordered_map<int,int> cnt;
        for(int i = 0, j = 0, pairCnt = 0,n = nums.size(); i<n; ++i){
            while(j < n && pairCnt < k){
                pairCnt += cnt[nums[j]]++;
                ++j;
            }
            if(pairCnt >= k) ret += n - j + 1;
            pairCnt -= --cnt[nums[i]];
        }

        return ret;
    }
};
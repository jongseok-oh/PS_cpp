class Solution {
    typedef long long ll;
public:
    ll countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int _max = *max_element(nums.begin(), nums.end());

        ll ret = 0;
        int maxCnt = 0;
        for(int i = 0, j = 0; j<n; ++j){
            if(nums[j] == _max) ++maxCnt;
            if(maxCnt == k){
                while(maxCnt == k){
                    ret += n - j;
                    if(nums[i++] == _max) --maxCnt;
                }
            }
        }
        return ret;
    }
};
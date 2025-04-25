class Solution {
    using ll = long long;
public:
    ll countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        nums[0] = (nums[0] % modulo == k) % modulo;
        for(int i = 1; i<n; ++i){
            int& num = nums[i];
            num = (num % modulo == k);
            num = (num + nums[i-1]) % modulo;
        }

        ll ret = 0;
        unordered_map<int, int> prevCnt;
        prevCnt[0] = 1;

        for(int i = 0; i<n; ++i){
            int pair = (nums[i] - k + modulo) % modulo;
            if(prevCnt.count(pair)){
                ret += prevCnt[pair] ;
            }
            ++prevCnt[nums[i]];
        }

        return ret;
    }
};
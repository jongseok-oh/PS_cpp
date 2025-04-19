class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long ret = 0;
        int postiveCnt = 0,minDiff = 1e9;
        for(int num: nums){
            int conv = num ^ k, diff = conv - num;

            if(diff > 0){
                ret += conv;
                ++postiveCnt;
            }else ret += num;
            
            minDiff = min(minDiff, abs(diff));
        }
        return postiveCnt&1?ret-minDiff:ret;
    }
};
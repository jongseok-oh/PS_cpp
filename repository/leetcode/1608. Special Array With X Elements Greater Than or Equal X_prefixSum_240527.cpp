class Solution {
    int prefixCnt[1002];
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int num : nums) ++prefixCnt[num];
        
        for(int i = 1000; i>=0; --i){
            prefixCnt[i] += prefixCnt[i + 1];
            if(prefixCnt[i] == i) return i;
        }
        return -1;
    }
};
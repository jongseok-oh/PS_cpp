class Solution {
    bool isBigger(vector<int>& bitCnt, int k){
        for(int i = 30; i>=0; --i){
            if(bitCnt[i] > 0 && !((1<<i) & k)) return true;
            else if(((1<<i) & k) && bitCnt[i] <= 0) return false;
        }
        return true;
    }
    void addBit(vector<int>& bitCnt, int num){
        for(int bit = 0; bit<31; ++bit){
            if((1<<bit)&num) ++bitCnt[bit];
        }
    }
    void popBit(vector<int>& bitCnt, int num){
        for(int bit = 0; bit<31; ++bit){
            if((1<<bit)&num) --bitCnt[bit];
        }
    }
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        if(k == 0) return 1;
        vector<int> bitCnt(31);
        int ret = 1e9;
        for(int i = 0, j = 0, n = nums.size(); i<n; ++i){
            while(j<n && !isBigger(bitCnt, k)){
                addBit(bitCnt, nums[j++]);
            }
            if(isBigger(bitCnt, k)){
                ret = min(ret, j - i);
            }
            popBit(bitCnt, nums[i]);
        }
        return ret==1e9?-1:ret;
    }
};
class Solution {

public:
    int minKBitFlips(vector<int>& nums, int k) {
        bool flip = false;
        int n = nums.size(), ret = 0;
        vector<bool> prevFlip(n);
        
        for(int i = 0; i<n; ++i){
            if(i >= k) flip ^= prevFlip[i-k];
            if(flip == nums[i]){
                if(i > n -k) return -1;
                prevFlip[i] = true;
                flip ^= 1;
                ++ret;
            }
        }
        return ret;
    }
};
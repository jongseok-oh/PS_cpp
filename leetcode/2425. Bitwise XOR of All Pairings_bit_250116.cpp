class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        
        int ret = 0;
        if(m&1){
            for(int num : nums1) ret ^= num;
        }
        if(n&1){
            for(int num : nums2) ret ^= num;
        }

        return ret;
    }
};
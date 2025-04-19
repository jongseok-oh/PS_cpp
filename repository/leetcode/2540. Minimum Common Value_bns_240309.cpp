class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        for(int num: nums1){
            auto it = lower_bound(nums2.begin(), nums2.end(), num);
            if(it != nums2.end() && *it == num) return num;
        }
        return -1;
    }
};
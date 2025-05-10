class Solution {
    using ll = long long;
public:
    ll minSum(vector<int>& nums1, vector<int>& nums2) {
        ll sum1 = 0, zero1 = 0;
        for(int num : nums1){
            if(num == 0){
                ++sum1;
                ++zero1;
            }else sum1 += num;
        }
        ll sum2 = 0, zero2 = 0;
        for(int num : nums2){
            if(num == 0){
                ++sum2;
                ++zero2;
            }else sum2 += num;
        }

        if(sum1 == sum2) return sum1;
        if(sum1 > sum2 && zero2 > 0) return sum1;
        if(sum1 < sum2 && zero1 > 0) return sum2;
        
        return -1;
    }
};
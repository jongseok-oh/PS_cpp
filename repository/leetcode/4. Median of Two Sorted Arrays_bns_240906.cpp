class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if(n > m) return findMedianSortedArrays(nums2, nums1);

        int halfCnt = (n + m + 1)/2;
        int low = -1, high = n+1;
        while(low + 1 < high){
            int nCnt = (low + high)>>1;
            int mCnt = halfCnt - nCnt;

            int nLeftMax = (nCnt?nums1[nCnt-1]:-1e9);
            int nRightMin = (nCnt==n?1e9:nums1[nCnt]);
            int mLeftMax = (mCnt?nums2[mCnt-1]:-1e9);
            int mRightMin = (mCnt==m?1e9:nums2[mCnt]);

            if(nLeftMax <= mRightMin && mLeftMax <= nRightMin){
                int leftMax = max(nLeftMax, mLeftMax);
                if((n+m)&1){
                    return leftMax;
                }else {
                    int rightMin = min(nRightMin, mRightMin);
                    return 1.0 * (leftMax + rightMin)/2;
                }
            }

            if(nLeftMax > mRightMin) high = nCnt;
            else low = nCnt;
        }
        
        return 1e9;
    }
};
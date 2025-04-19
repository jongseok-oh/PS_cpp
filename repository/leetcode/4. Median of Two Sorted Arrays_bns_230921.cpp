class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            nums1.swap(nums2);
        }

        int len1 = nums1.size();
        int len2 = nums2.size();

        int left = 0;
        int right = len1;

        while (left <= right) {
            int partition1 = (left + right) / 2;
            int partition2 = (len1 + len2 + 1) / 2 - partition1;

            int maxLeft1 = partition1 > 0 ? nums1[partition1 - 1] : INT_MIN;
            int maxLeft2 = partition2 > 0 ? nums2[partition2 - 1] : INT_MIN;
            int maxLeft = max(maxLeft1, maxLeft2);

            int minRight1 = partition1 < len1 ? nums1[partition1] : INT_MAX;
            int minRight2 = partition2 < len2 ? nums2[partition2] : INT_MAX;
            int minRight = min(minRight1, minRight2);

            if (maxLeft <= minRight) {
                if ((len1 + len2) % 2 == 0) {
                    return (maxLeft + minRight) / 2.0;
                }
                else {
                    return maxLeft;
                }
            } else if (maxLeft1 > minRight2) {
                right = partition1 - 1;
            } else {
                left = partition1 + 1;
            }
        }

        return 0.0; 
    }
};
class Solution {
    public int compareVersion(String version1, String version2) {
        String[] nums1 = version1.split("\\.");
        String[] nums2 = version2.split("\\.");

        int n = Math.max(nums1.length, nums2.length);

        for(int i = 0; i<n; ++i){
            int num1 = 0, num2 = 0;
            if(nums1.length > i) num1 = Integer.parseInt(nums1[i]);
            if(nums2.length > i) num2 = Integer.parseInt(nums2[i]);
            if(num1 > num2) return 1;
            if(num1 < num2) return -1;
        }

        return 0;
    }
}
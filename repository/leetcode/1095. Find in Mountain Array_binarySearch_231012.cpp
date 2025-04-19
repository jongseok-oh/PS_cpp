/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
    int findTop(MountainArray &arr){
        int low = 0, high = arr.length() -1;
        while(low + 1< high){
            int mid = (low + high)>>1;

            if(arr.get(mid) > arr.get(mid+1)) high = mid;
            else low = mid;
        }
        return high;
    }
    int solve(int target, int top, MountainArray &arr){
        int low = -1, high = top + 1;
        while(low + 1 < high){
            int mid = (low + high)>>1;
            int val = arr.get(mid);

            if(val == target) return mid;
            else if(val > target) high = mid;
            else low = mid;
        }
        low = top, high = arr.length();
        while(low + 1 < high){
            int mid = (low + high)>>1;
            int val = arr.get(mid);

            if(val == target) return mid;
            else if(val < target) high = mid;
            else low = mid;
        }
        return -1;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        return solve(target, findTop(mountainArr), mountainArr);
    }
};
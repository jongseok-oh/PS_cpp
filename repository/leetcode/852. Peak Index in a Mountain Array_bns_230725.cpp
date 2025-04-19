class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0, high = arr.size() - 2;

        while(low + 1< high){
            int mid = (low + high) >>1;

            if(arr[mid]> arr[mid+1]) high = mid;
            else low = mid;
        }
        return high;
    }
};
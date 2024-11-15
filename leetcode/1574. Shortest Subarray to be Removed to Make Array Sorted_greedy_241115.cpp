class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int right = n - 1;
        while(right > 0 && arr[right] >= arr[right - 1]) --right;

        int ans = right;
        if(ans <= 1) return ans;
        
        for(int left = 0; left<n; ++left){
            if((left && arr[left-1] > arr[left]) || left >= right) break;
            while(right < n && arr[left] > arr[right]) ++right;
            ans = min(ans, right - left - 1);
        }

        return ans;
    }
};
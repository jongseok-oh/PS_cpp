class Solution {
    const int DIFF = 10000;
    int sufSum[20020];
public:
    int findKthLargest(vector<int>& nums, int k) {
        int MAX = -1e9;
        for(int& num: nums) {
            sufSum[num + DIFF]++;
            MAX = max(MAX, num + DIFF);
        }

        for(int i = MAX; i>=0; i--) {
            sufSum[i] += sufSum[i + 1];
            if(sufSum[i] >= k) return i - DIFF;
        }

        return -1;
    }
};
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int numerator, denominator, n = arr.size();
        double low = 0, high = 1;

        while(low + 1e-8 < high){
            double mid = (low + high)/2, _max = 0;
            
            int smallCnt = 0;
            for(int i = 0, j = 1; i<n; ++i){
                while(j<n && arr[i] >= arr[j] * mid) ++j;

                if(j>=n) break;
                smallCnt += n - j;
                double calc = (double)arr[i]/arr[j];
                if(calc > _max){
                    _max = calc;
                    numerator = arr[i]; denominator = arr[j];
                }
            }

            if(smallCnt == k) return {numerator, denominator};
            
            if(smallCnt > k) high = mid;
            else low = mid;
        }
        return {-1,-1};
    }
};
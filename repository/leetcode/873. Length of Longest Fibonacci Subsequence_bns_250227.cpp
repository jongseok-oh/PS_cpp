class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        int ret = 0;
        for(int i = 0; i<n-2; ++i){
            for(int j = i + 1; j<n-1; ++j){
                int idx1 = i, idx2 = j, len = 2;
                while(true){
                    int sum = arr[idx1] + arr[idx2];
                    auto it = lower_bound(arr.begin() + idx2 + 1, arr.end(), sum);
                    if(it == arr.end() || sum != *it) break;
                    idx1 = idx2;
                    idx2 = it - arr.begin();
                    ++len;
                }
                if(len >= 3) ret = max(ret, len);
            }
        }

        return ret;
    }
};
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();

        int ret = 0;
        for(int i = 0; i<n; ++i){
            int _max = arr[i];
            while(i < n && i != _max){
                _max = max(_max, arr[++i]);
            }
            ++ret;
        }

        return ret;
    }
};
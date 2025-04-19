class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 0;

        vector<int> prefixXor(n+1);

        for(int i = 0; i<n; ++i)
            prefixXor[i + 1] = arr[i] ^ prefixXor[i];
        
        int cnt = 0;

        // n^2
        for(int i = 0; i<n-1; ++i){
            for(int j = i + 1; j<n; ++j){
                if(prefixXor[i] == prefixXor[j + 1]){
                    cnt += j - i;
                }
            }
        }
        return cnt;
    }
};
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 0;

        vector<int> prefixXor(n+1);

        for(int i = 0; i<n; ++i)
            prefixXor[i + 1] = arr[i] ^ prefixXor[i];
        
        int cnt = 0;

        // n^3
        for(int i = 0; i<n-1; ++i){
            for(int j = i + 1; j<n; ++j){
                for(int k = j; k<n; ++k){
                    int a = prefixXor[i] ^ prefixXor[j];
                    int b = prefixXor[j] ^ prefixXor[k+1];
                    cnt += a==b;
                }
            }
        }
        return cnt;
    }
};
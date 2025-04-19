class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefixXor(n + 1);

        for(int i = 0; i<n; ++i){
            prefixXor[i+1] = prefixXor[i] ^ arr[i];
        }
        int m = queries.size();
        vector<int> result(m);
        for(int i = 0; i<m; ++i){
            int s = queries[i][0], e = queries[i][1];
            result[i] = prefixXor[e+1] ^ prefixXor[s];
        }

        return result;
    }
};
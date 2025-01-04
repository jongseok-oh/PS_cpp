class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<vector<int>> prefixSum(n+1, vector<int>(26));

        for(int i = 0; i<n; ++i){
            ++prefixSum[i+1][s[i] - 'a'];
            for(int j = 0; j<26; ++j){
                prefixSum[i+1][j] += prefixSum[i][j];
            }
        }

        bitset<26> visit;
        int ret = 0;
        for(int i = 0; i<n-1; ++i){
            if(visit[s[i] -'a']) continue;
            visit[s[i] -'a'] = true;
            int j = n-1;
            while(i < j && s[i] != s[j]) --j;
            
            if(i + 1 < j){
                for(int k = 0; k<26; ++k){
                    int cnt = prefixSum[j][k] - prefixSum[i+1][k];
                    if(cnt) ++ret;
                }
            }
        }

        return ret;
    }
};
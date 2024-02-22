class Solution {
    int f[1001], t[1001];
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        for(auto& tru: trust){
            f[tru[0]]++; t[tru[1]]++;
        }
        
        for(int i = 1; i<=n; ++i)
            if(!f[i] && t[i] == n-1) return i;

        return -1;
    }
};
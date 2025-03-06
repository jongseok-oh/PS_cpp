class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> cnt(n * n + 1), ret(2);
        
        for(auto& row : grid){
            for(int num : row) ++cnt[num];
        }
        
        for(int i = 1; i<=n*n; ++i){
            if(cnt[i] == 2) ret[0] = i;
            else if(cnt[i] == 0) ret[1] = i;
        }
        
        return ret;
    }
};
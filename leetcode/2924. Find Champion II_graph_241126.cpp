class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indeg(n);
        for(auto& edge : edges){
            ++indeg[edge[1]];
        }

        int ret = -1, cnt = 0;
        for(int i = 0; i<n; ++i){
            if(indeg[i] == 0){
                ret = i;
                ++cnt;
            }
        }
        return cnt == 1?ret:-1;
    }
};
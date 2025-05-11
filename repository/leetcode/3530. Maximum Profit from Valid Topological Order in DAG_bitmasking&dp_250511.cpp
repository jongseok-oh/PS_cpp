class Solution {
    int solve(int n, int pivot, int visit, int order, vector<int>& dp, vector<vector<int>>& con, vector<int>& score, vector<int>& parent){
        if(visit == (1<<n) - 1) return 0;
        
        int& ret = dp[visit];
        if(ret != -1) return ret;
        
        ret = 0;
        for(int i = 0; i<n; ++i){
            if(pivot & (1<<i)){
                int nVisit = visit | (1<<i);
                int nPivot = pivot ^ (1<<i);
                for(int next : con[i]){
                    if((parent[next] & nVisit) == parent[next]){
                        nPivot |= (1<<next);
                    }
                }
                ret = max(ret, solve(n, nPivot, nVisit, order + 1, dp, con, score, parent) + order * score[i]);
            }
        }
        
        return ret;
    }
public:
    int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {
        vector<vector<int>> con(n);
        vector<int> parent(n);
        for(auto& e : edges){
            int f = e[0], t = e[1];
            con[f].push_back(t);
            parent[t] |= (1<<f);
        }  
        
        int pivot = 0;
        for(int i = 0; i<n; ++i){
            if(parent[i] == 0) pivot |= (1<<i);
        }
        
        vector<int> dp(1<<n, -1);
        return solve(n, pivot, 0, 1, dp, con, score, parent);
    }
};
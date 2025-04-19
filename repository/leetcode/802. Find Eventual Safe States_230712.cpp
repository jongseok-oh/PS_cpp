class Solution {
    int safe[10000];

    int chk(int t, vector<vector<int>>& g){
        int& ret = safe[t];

        if(ret != -1) return ret;

        ret = 0;

        for(int next: g[t])
            if(chk(next, g) == 0) return ret = 0;

        return ret = 1;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        memset(safe, -1, 4* n);

        vector<int> ans;

        for(int i = 0; i<n; i++)
            if(!graph[i].size()) safe[i] = 1;
        
        for(int i = 0; i<n; i++)
            if(chk(i, graph) == 1) ans.push_back(i);
        
        return ans;
    }
};
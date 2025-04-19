class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> con(n);
        vector<unordered_set<int>> ret(n);
        vector<int> indeg(n);

        for(auto& edge: edges){
            indeg[edge[1]]++;
            con[edge[0]].push_back(edge[1]);
        }

        queue<int> q;
        for(int i = 0; i<n; ++i)
            if(indeg[i] == 0) q.push(i);
        
        while(q.size()){
            int node = q.front(); q.pop();
            for(int next: con[node]){
                auto& c = ret[next];
                auto& p = ret[node];
                c.insert(p.begin(), p.end());
                c.insert(node);
                if(--indeg[next] == 0) q.push(next);
            }
        }

        vector<vector<int>> ans(n);

        for(int i = 0; i<n; ++i){
            auto& t = ans[i];
            auto& r = ret[i];
            t.insert(t.end(), r.begin(), r.end());
            sort(t.begin(), t.end());
        }
        return ans;
    }
};
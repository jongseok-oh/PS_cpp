class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> indegree(n);
        vector<vector<int>> con(n);
        for(int i = 0; i<n; ++i){
            for(int nNode : graph[i]){
                ++indegree[i];
                con[nNode].push_back(i);
            }
        }

        queue<int> q;
        
        for(int i = 0; i<n; ++i){
            if(indegree[i] == 0) q.push(i);
        }

        vector<bool> safe(n);
        while(q.size()){
            int t = q.front(); q.pop();
            safe[t] = true;
            for(int nNode : con[t]){
                if(--indegree[nNode] == 0){
                    q.push(nNode);
                }
            }
        }

        vector<int> ret;
        for(int i = 0; i<n; ++i){
            if(safe[i]) ret.push_back(i);
        }

        return ret;
    }
};
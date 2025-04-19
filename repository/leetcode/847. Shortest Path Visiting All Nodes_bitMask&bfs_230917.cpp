class Solution {
    vector<int> con[12];
    bool visit[12][1<<12];
    struct State{int node, mask;};
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();

        for(int i = 0; i<n; ++i) for(int j = 0; j<graph[i].size(); ++j)
            con[i].push_back(graph[i][j]);
        
        queue<State> q;

        for(int i = 0; i<n; i++) q.push({i, 1<<i});

        int ret = 0, allVisit = (1<<n)-1;
        while(q.size()){
            int qsize = q.size();

            while(qsize--){
                State tState = q.front(); q.pop();
                
                int tNode = tState.node, tMask = tState.mask;

                if(tMask == allVisit) return ret;

                for(int& nNode: con[tNode]){
                    int nMask = tMask | (1<<nNode);

                    if(!visit[nNode][nMask]){
                        visit[nNode][nMask] = true;
                        q.push({nNode, nMask});
                    }
                }
            }
            ++ret;
        }

        return ret;
    }
};
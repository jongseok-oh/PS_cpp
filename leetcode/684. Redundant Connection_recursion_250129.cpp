class Solution {
    using pii = pair<int,int>;
    int cycleStart = -1;
    bool isCycle = false;
    int findRemoveEdge(int node, int parent, vector<bool>& visit, vector<vector<pii>>& con){
        visit[node] = true;
        for(const auto& [next, idx] : con[node]){
            if(next == parent) continue;
            if(visit[next]) {
                cycleStart = next;
                isCycle = true;
                return idx;
            }
            
            int ret = findRemoveEdge(next, node, visit, con);
            if(ret != -1) {
                if(cycleStart == node) {
                    isCycle = false;
                    return max(ret, idx);
                }
                return isCycle?max(ret, idx):ret;
            }
        }

        return -1;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<pii>> con(n + 1);

        for(int i = 0; i<n; ++i){
            auto& edge = edges[i];
            int a = edge[0], b = edge[1];
            con[a].emplace_back(b, i);
            con[b].emplace_back(a, i);
        }
        
        vector<bool> visit(n+1);
        cycleStart = -1;
        int idx = findRemoveEdge(1, -1, visit, con);
        return edges[idx];
    }
};
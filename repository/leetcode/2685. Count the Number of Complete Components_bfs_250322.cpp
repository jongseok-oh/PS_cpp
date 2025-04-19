class Solution {
    using pii = pair<int,int>;

    bool isComplete(int node, vector<vector<pii>>& con, vector<bool>& nodeVisit,vector<bool>& edgeVisit){
        queue<int> q;
        q.push(node);
        nodeVisit[node] = true;

        int edgeCnt = 0, nodeCnt = 1;
        while(q.size()){
            int t = q.front(); q.pop();
            
            for(auto& [next, idx] : con[t]){
                if(edgeVisit[idx]) continue;
                if(!nodeVisit[next]){
                    nodeVisit[next] = true;
                    ++nodeCnt;
                }
                ++edgeCnt;
                edgeVisit[idx] = true;
                q.push(next);
            }
        }

        return edgeCnt == ((nodeCnt - 1) * nodeCnt /2);
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int m = edges.size();

        vector<vector<pii>> con(n);
        for(int i = 0; i<m; ++i){
            int a = edges[i][0], b = edges[i][1];
            con[a].emplace_back(b, i);
            con[b].emplace_back(a, i);
        }

        int ret = 0;
        vector<bool> nodeVisit(n),edgeVisit(m);
        for(int i = 0; i<n; ++i){
            if(!nodeVisit[i] && isComplete(i, con, nodeVisit, edgeVisit)){
                ++ret;
            }
        }
        return ret;
    }
};
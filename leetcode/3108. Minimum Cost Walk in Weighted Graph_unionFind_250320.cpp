class Solution {
    using tiii = tuple<int, int, int>;
    vector<int> parent;
    unordered_map<int,int> groupCost;

    int getParent(int t){
        if(parent[t] == t) return t;
         return parent[t] = getParent(parent[t]);
    }

    void merge(int a, int b){
        int ap = getParent(a), bp = getParent(b);
        if(ap == bp) return;
        if(ap < bp) parent[bp] = ap;
        else parent[ap] = bp;
    }
    void bfs(int node, vector<vector<tiii>>& con, vector<bool>& edgeVisit){
        queue<int> q;
        q.push(node);
        parent[node] = node;

        int ret = 0x7fffffff;
        while(q.size()){
            int t = q.front(); q.pop();

            for(auto& [next, cost, idx] : con[t]){
                if(edgeVisit[idx]) continue;
                if(parent[next] == -1) parent[next] = next;
                edgeVisit[idx] = true;
                ret &= cost;
                merge(t, next);
                q.push(next);
            }
        }
        groupCost[node] = ret;
    }
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        int m = edges.size();
        vector<vector<tiii>> con(n);
        for(int i = 0; i<m; ++i){
            auto& edge = edges[i];
            int u = edge[0], v = edge[1], w = edge[2];
            con[u].emplace_back(v, w, i);
            con[v].emplace_back(u, w, i);
        }

        parent = vector<int>(n, -1);
        vector<bool> edgeVisit(m);
        for(int i = 0; i<n; ++i){
            if(parent[i] == -1) bfs(i, con, edgeVisit);
        }

        int k = query.size();
        vector<int> ret(k);
        for(int i = 0; i<k; ++i){
            int s = query[i][0], t = query[i][1];
            int sp = getParent(s), tp = getParent(t);
            ret[i] = sp != tp?-1:groupCost[sp];
        }

        return ret;
    }
};
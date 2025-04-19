class Solution {
    struct Edge{
        int from, to, cost;
    };

    int parent[1001];
    int getP(int t){
        if(!parent[t]) return t;
        return parent[t] = getP(parent[t]);
    }

    bool merge(int a, int b){
        int ap = getP(a);
        int bp = getP(b);

        if(ap == bp) return false;

        parent[bp] = ap;
        return true;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
          vector<Edge> edges;

          for(int i = 0; i<n; ++i) for(int j = i + 1; j<n; j++){
              int tCost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
              edges.push_back({i + 1,j + 1, tCost});
            }
        
        sort(edges.begin(), edges.end(), [](const auto& a, const auto& b){
            return a.cost < b.cost;
        });

        int cnt = 0, ret = 0;

        for(auto& edge: edges){
            if(merge(edge.from, edge.to)){
                ret += edge.cost;
                if(++cnt == n-1) break;
            }
        }

        return ret;
    }
};
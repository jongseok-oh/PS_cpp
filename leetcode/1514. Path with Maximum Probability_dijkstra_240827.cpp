static const int _ = []{cin.tie(0);ios::sync_with_stdio(0);return 0;}();
class Solution {
    using pdi = pair<double, int>;
    vector<pdi> con[10000];

    double dijkstra(int s, int e, int n){
        vector<double> dist(n, 0);
        priority_queue<pdi,vector<pdi>, greater<pdi>> q;
        dist[s] = -1;
        q.emplace(-1, s);

        while(q.size()){
            auto [tprob, node] = q.top(); q.pop();
            if(node == e) return -tprob;
            if(dist[node] < tprob) continue;
            
            for(auto [prob, nNode]:con[node]){
                double nProb = tprob * prob;
                if(dist[nNode] > nProb){
                    dist[nNode] = nProb;
                    q.emplace(nProb, nNode);
                }
            }
        }
        return 0;
    }
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        int m = edges.size();
        for(int i = 0; i<m; ++i){
            auto& edge = edges[i];
            int a = edge[0], b = edge[1];
            double prob = succProb[i];

            con[a].emplace_back(prob, b);
            con[b].emplace_back(prob, a);
        }
        return dijkstra(start_node, end_node, n);
    }
};
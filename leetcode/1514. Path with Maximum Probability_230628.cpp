class Solution {
    struct Loc{
        int node;
        double cost;
        bool operator < (const Loc& a) const{
            return cost < a.cost;
        }
    };

    vector<Loc> edge[10000];
    double dist[10000];
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {

        for(int i = 0; i<edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];
            double cost = succProb[i];

            edge[a].push_back({b,cost});
            edge[b].push_back({a,cost});
        }

        for(int i = 0; i<n; i++) dist[i] = -1.0;

        priority_queue<Loc> pq;

        dist[start] = 1.0;
        pq.push({start, 1.0});

        while(pq.size()){
            auto loc = pq.top(); pq.pop();
            int node = loc.node;
            double cost = loc.cost;

            if(node == end) return cost;
            if(dist[node] > cost) continue;

            for(auto& nLoc : edge[node]){
                int nNode = nLoc.node;
                double nCost = nLoc.cost;
                if(dist[nNode] < nCost * cost){
                    dist[nNode] = nCost * cost;
                    pq.push({nNode, dist[nNode]});
                }
            }
        }

        return 0;
    }
};
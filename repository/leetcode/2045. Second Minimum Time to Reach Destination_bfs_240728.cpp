class Solution {
    using pii = pair<int, int>;
    vector<int> con[10001];
    const int INF = 0x3f3f3f3f;
    int dist[10001], dist2[10001];
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        for(auto& e: edges){
            con[e[0]].push_back(e[1]);
            con[e[1]].push_back(e[0]);
        }
        memset(dist, 0x3f, sizeof dist);
        memset(dist2, 0x3f, sizeof dist2);

        queue<pii> q;
        q.emplace(1,0);
        dist[1] = 0;
        while(q.size()){
            auto [node, cost] = q.front(); q.pop();
            for(int next : con[node]){
                int ncost = cost;
                if((ncost/change)&1){
                    ncost += change - ncost%change;
                }
                ncost += time;
                if(dist[next] == INF){
                    dist[next] = ncost;
                    q.emplace(next, ncost);
                }else if(dist[next] != ncost && dist2[next] == INF){
                    dist2[next] = ncost;
                    q.emplace(next, ncost);
                }
            }
        }
        return dist2[n];
    }
};
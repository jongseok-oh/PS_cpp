class Solution {
    using ll = long long;
    using pii = pair<int, int>;
    using pli = pair<ll, int>;
    const int MOD = 1e9 + 7;

    void dijkstra(vector<ll>& dist, vector<vector<pii>>& con){
        priority_queue<pli, vector<pli>, greater<>> q;
        q.emplace(0, 0);
        dist[0] = 0;

        while(q.size()){
            auto [tCost, node] = q.top(); q.pop();
            if(dist[node] < tCost) continue;

            for(auto& [next, cost] : con[node]){
                ll nCost = tCost + cost;
                if(dist[next] > nCost){
                    dist[next] = nCost;
                    q.emplace(nCost, next);
                }
            }
        }
    }
    int countPaths(int node, vector<int>& dp, vector<ll>& dist, vector<vector<pii>>& con){
        if(node == 0) return 1;
        int& ret = dp[node];
        if(ret != -1) return ret;
        ret = 0;
        for(auto& [prev, cost] : con[node]){
            if(dist[node] - cost == dist[prev]){
                ret = (ret + countPaths(prev, dp, dist, con)) % MOD;
            }
        }
        return ret;
    }
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pii>> con(n);
        for(auto& road : roads){
            int u = road[0], v = road[1], time = road[2];
            con[u].emplace_back(v, time);
            con[v].emplace_back(u, time);
        }

        vector<ll> dist(n, LLONG_MAX);
        dijkstra(dist, con);
        vector<int> dp(n,-1);
        return countPaths(n-1, dp, dist, con);
    }
};
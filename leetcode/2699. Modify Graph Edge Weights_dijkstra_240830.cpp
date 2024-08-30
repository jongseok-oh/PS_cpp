class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        for(int i = 0; i<edges.size(); ++i){
            int a = edges[i][0], b = edges[i][1], cost = edges[i][2];
            addEdge(a,b, i);
        }
        vector<vector<int>> dist(n, vector<int>(2, 1e9 + 1));

        int minDist = dijkstra(source, destination, target, dist, edges);
        if(minDist > target) return {};

        int tarDist = dijkstra2(source, destination, target, target - minDist, dist, edges);
        if(tarDist < target) return {};

        for(auto& edge : edges){
            if(edge[2] == -1){
                edge[2] = 1e9;
            }
        }

        return edges;
    }
private:
    using pii = pair<int, int>;
    
    vector<pii> con[100];
    void addEdge(int a, int b, int idx){
        con[a].push_back({b, idx});
        con[b].push_back({a, idx});
    }

    int dijkstra(int s, int d, int target, vector<vector<int>>& dist, vector<vector<int>>& edges){
        priority_queue<pii, vector<pii>, greater<>> q;
        dist[s][0] = 0;
        q.emplace(0, s);

        while(q.size()){
            auto [tcost, node] = q.top(); q.pop();
            if(dist[node][0] < tcost) continue;

            for(auto& [to, idx] : con[node]){
                int cost = edges[idx][2];
                int nCost = tcost + (cost==-1?1:cost);
                if(dist[to][0] > nCost){
                    dist[to][0] = nCost;
                    q.emplace(nCost, to);
                }
            }
        }
        
        return dist[d][0];
    }

    int dijkstra2(int s, int d, int target, int diff, vector<vector<int>>& dist, vector<vector<int>>& edges){
        priority_queue<pii, vector<pii>, greater<>> q;
        dist[s][1] = 0;
        q.emplace(0, s);

        while(q.size()){
            auto [tcost, node] = q.top(); q.pop();
            if(node == d) return tcost;
            if(dist[node][1] < tcost) continue;

            for(auto& [to, idx] : con[node]){
                int cost = (edges[idx][2]==-1?1:edges[idx][2]);
                if(edges[idx][2] == -1){
                    int calcDist = diff - tcost + dist[to][0];
                    if(calcDist >= cost){
                        edges[idx][2] = cost = calcDist;
                    }
                }
                int nCost = tcost + cost;
                if(dist[to][1] > nCost){
                    dist[to][1] = nCost;
                    q.emplace(nCost, to);
                }
            }
        }
        
        return -1;
    }
};
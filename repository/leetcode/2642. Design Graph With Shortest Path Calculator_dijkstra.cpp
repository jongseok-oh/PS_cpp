class Graph {
    int _n;

    struct Edge{
        int t,cost;

        bool operator < (const Edge& e) const{
            return cost > e.cost;
        }
    };

    vector<Edge> con[100];
public:
    Graph(int n, vector<vector<int>>& edges) {
        _n = n;

        for(auto& edge: edges) addEdge(edge);
    }
    
    void addEdge(vector<int> edge) {
        int f = edge[0];
        int t = edge[1];
        int cost = edge[2];

        con[f].push_back({t,cost});
    }
    
    int shortestPath(int node1, int node2) {
        vector<int> dist(_n, 1e9);

        priority_queue<Edge> q;

        q.push({node1, 0});
        dist[node1] = 0;

        while(q.size()){
            auto tt = q.top(); q.pop();
            int t = tt.t, tCost = tt.cost;

            if(t == node2) return tCost;
            if(dist[t] < tCost) continue;

            for(auto& edge: con[t]){
                int nNode = edge.t, nCost = edge.cost;

                if(dist[nNode] > tCost + nCost){
                    dist[nNode] = tCost + nCost;
                    q.push({nNode, tCost + nCost});
                }
            }
        }

        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
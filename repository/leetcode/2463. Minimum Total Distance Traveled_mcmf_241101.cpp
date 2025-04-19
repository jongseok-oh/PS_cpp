class Solution {
    using ll = long long;
    int s = 200, d = 201;
    struct Edge{
        ll to, cap, cost, rev;
    };
    vector<Edge> con[202];
    void addEdge(int from, int to, int cap, int cost){
        con[from].push_back({to, cap, cost, (int)con[to].size()});
        con[to].push_back({from, 0, -cost, (int)con[from].size() - 1});
    }
    void makeGraph(vector<int>& robot, vector<vector<int>>& factory){
        int n = robot.size(), m = factory.size();
        for(int i = 0; i<n; ++i){
            addEdge(s, i, 1, 0);
            for(int j = 0; j<m; ++j){
                int dist = abs(robot[i] - factory[j][0]);
                addEdge(i, n + j, 1, dist);
            }
        }
        for(int j = 0; j<m; ++j){
            addEdge(j + n, d, factory[j][1], 0);
        }
    }

    const ll INF = 0x3f3f3f3f3f;
    ll dist[202];
    bool inQ[202];
    int prevv[202], preve[202];
    ll spfa(){
        memset(dist, 0x3f, sizeof dist);
        memset(inQ, 0, sizeof inQ);
        
        queue<int> q; q.push(s);
        dist[s] = 0;
        while(q.size()){
            int t = q.front(); q.pop();
            inQ[t] = false;

            for(int i = 0, n = con[t].size(); i<n; ++i){
                Edge& e = con[t][i];
                if(e.cap > 0 && dist[e.to] > dist[t] + e.cost){
                    dist[e.to] = dist[t] + e.cost;
                    prevv[e.to] = t;
                    preve[e.to] = i;
                    if(!inQ[e.to]){
                        inQ[e.to] = true;
                        q.push(e.to);
                    }
                }
            }
        }
        return dist[d];
    }

    ll mcmf(){
        ll ret = 0, temp = 0;
        while(INF > (temp = spfa())){
            ret += temp;
            for(int v = d; v != s; v = prevv[v]){
                int p = prevv[v];
                Edge& e = con[p][preve[v]];
                --e.cap;
                ++con[v][e.rev].cap;
            }
        }
        return ret;
    }
public:
    ll minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        makeGraph(robot, factory);
        return mcmf();
    }
};
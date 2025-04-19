class Solution {
    using pii = pair<int, int>;
    vector<int> getBobPath(vector<vector<int>>& con, int bob){
        int n = con.size();
        vector<int> parent(n, -1);

        queue<int> q;
        q.push(0);
        parent[0] = 0;

        while(q.size()){
            int t = q.front(); q.pop();

            if(t == bob) break;
            for(int next : con[t]){
                if(parent[next] != -1) continue;
                parent[next] = t;
                q.push(next);
            }
        }

        vector<int> path;
        for(int temp = bob; ;temp = parent[temp]){
            path.push_back(temp);
            if(temp == 0) break;
        }

        return path;
    }
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> con(n);
        for(auto& edge : edges){
            int from = edge[0], to = edge[1];
            con[from].push_back(to);
            con[to].push_back(from);
        }

        vector<int> bobPath = getBobPath(con, bob);
        
        int depth = 0, ret = -1e9;

        vector<bool> visit(n);
        queue<pii> q;
        q.emplace(0, 0);
        visit[0] = true;
        
        while(q.size()){
            int qsize = q.size();
            while(qsize--){
                auto [benefit, node] = q.front(); q.pop();

                int reward = amount[node];
                if(depth < bobPath.size() && bobPath[depth] == node){
                    reward /= 2;
                }
                
                benefit += reward;

                int inq = 0;
                for(int next : con[node]){
                    if(visit[next]) continue;
                    ++inq;
                    visit[next] = true;
                    q.emplace(benefit, next);
                }

                if(inq == 0) ret = max(ret, benefit);
            }

            if(depth < bobPath.size()) {
                amount[bobPath[depth]] = 0;
            }
            ++depth;
        }

        return ret;
    }
};
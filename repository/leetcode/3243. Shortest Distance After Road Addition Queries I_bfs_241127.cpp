class Solution {
    bool visit[500];
    int bfs(vector<vector<int>>& con, int n){
        queue<int> q;
        q.push(0);
        memset(visit, 0, n);
        visit[0] = true;

        int move = 0;
        while(q.size()){
            int qsize = q.size();
            while(qsize--){
                int t = q.front(); q.pop();
                if(t == n-1) return move;

                for(int next : con[t]){
                    if(visit[next]) continue;
                    visit[next] = true;
                    q.push(next);
                }
            }
            ++move;
        }

        return -1;
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> con(n);
        for(int i = 0; i<n-1; ++i) {
            con[i].push_back(i+1);
        }

        int m = queries.size();
        vector<int> ret(m);
        for(int i = 0; i<m; ++i){
            auto& q = queries[i];
            con[q[0]].push_back(q[1]);
            ret[i] = bfs(con, n);
        }

        return ret;
    }
};
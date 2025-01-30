class Solution {
    using pii = pair<int, int>;
    bool canDivide(int node, vector<int>& color, vector<vector<int>>& con){
        color[node] = 0;
        queue<int> q;
        q.push(node);

        while(q.size()){
            int t = q.front(); q.pop();
            for(int next : con[t]){
                if(color[next] == color[t]) return false;
                if(color[next] != -1) continue;
                color[next] = color[t] ^ 1;
                q.push(next);
            }
        }
        return true;
    }
    int bfs(int node, int n, vector<vector<int>>& con){
        vector<bool> visit(n);
        queue<int> q;
        
        visit[node] = true;
        q.push(node);

        int depth = 0, endNode = -1;
        while(q.size()){
            int qsize = q.size();
            ++depth;
            while(qsize--){
                int t = q.front(); q.pop();
                endNode = t;
                for(int next : con[t]){
                    if(visit[next]) continue;
                    visit[next] = true;
                    q.push(next);
                }   
            }
        }

        return depth;
    }
    int getMaxLen(int node, int n, vector<bool>& visit, vector<vector<int>>& con){
        visit[node] = true;
        int maxLen = bfs(node, n, con);
        for(int next : con[node]){
            if(visit[next]) continue;
            maxLen = max(maxLen, getMaxLen(next, n, visit, con));
        }
        return maxLen;
    }
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> con(n);
        for(auto& edge : edges){
            int a = edge[0]-1, b = edge[1]-1;
            con[a].push_back(b);
            con[b].push_back(a);
        }

        vector<int> color(n, -1);
        int ret = 0;
        vector<bool> visit(n);
        for(int i = 0; i<n; ++i){
            if(color[i] != -1) continue;
            if(!canDivide(i, color, con)) return -1;
            if(visit[i]) continue;
            ret += getMaxLen(i, n, visit, con);
        }

        return ret;
    }
};
class Solution {
    vector<int> con[200001];
    bool visit[200001];
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination) return true;

        for(auto& edge: edges){
            int a = edge[0], b = edge[1];
            con[a].push_back(b);
            con[b].push_back(a);
        }
        queue<int> q;
        visit[source] = true;
        q.push(source);

        while(q.size()){
            int t = q.front(); q.pop();

            for(int next: con[t]){
                if(visit[next]) continue;
                if(next == destination) return true;
                visit[next] = true;
                q.push(next);
            }
        }

        return false;
    }
};
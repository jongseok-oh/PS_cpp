class Solution {
    using ll = long long;
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> con(n);
        for(auto edge : edges){
            int a = edge[0], b = edge[1];
            con[a].push_back(b);
            con[b].push_back(a);
        }
        int ret = 0;
        vector<bool> visit(n);
        function<ll(int)> dfs = [&](int node)->ll{
            visit[node] = true;
            ll sum = values[node];
            for(int next : con[node]){
                if(visit[next]) continue;
                ll cSum = dfs(next);
                if(cSum != -1) sum += cSum;
            }
            if(sum % k == 0){
                ++ret;
                return -1;
            }else return sum;
        };
        dfs(0);
        return ret;
    }
};
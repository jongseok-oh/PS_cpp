class Solution {
    void dfs(int t, int parent, vector<vector<int>>& con, vector<int>& cnt, vector<int>& sum){
        for(int next:con[t]){
            if(next == parent) continue;
            dfs(next, t, con, cnt, sum);
            cnt[t] += cnt[next];
            sum[t] += sum[next] + cnt[next];
        }
    }

    void dfs1(int t, int parent, vector<vector<int>>& con, vector<int>& cnt, vector<int>& sum){
        int n = cnt.size();
        for(int next:con[t]){
            if(next == parent) continue;
            sum[next] = sum[t] - cnt[next] + (n - cnt[next]);
            dfs1(next, t, con, cnt, sum);
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> con(n);
        for(auto& edge: edges){
            int a = edge[0], b = edge[1];
            con[a].push_back(b);
            con[b].push_back(a);
        }
        vector<int> cnt(n,1), sum(n);
        dfs(0, -1, con, cnt, sum);
        dfs1(0, -1, con, cnt, sum);
        return sum;
    }
};

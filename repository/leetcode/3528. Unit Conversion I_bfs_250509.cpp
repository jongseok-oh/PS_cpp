class Solution {
    const int MOD = 1e9 + 7;
    using pii = pair<int, int>;
    using ll = long long;
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int n = conversions.size();
        
        vector<vector<pii>> con(n + 1);
        vector<int> indeg(n+1);
        for(auto& conv : conversions){
            int s = conv[0], t = conv[1], factor = conv[2];
            ++indeg[t];
            con[s].push_back({t, factor});
        }
        
        queue<int> q;
        for(int i = 0; i<n; ++i){
            if(!indeg[i]) q.push(i);
        }
        
        vector<int> ret(n + 1, 1);
        while(q.size()){
            int i = q.front(); q.pop();
            for(auto& [next, factor] : con[i]){
                ret[next] = (ll)ret[next] * ret[i] * factor % MOD;
                if(--indeg[next] == 0) q.push(next);
            }
        }
        
        return ret;
    }
};
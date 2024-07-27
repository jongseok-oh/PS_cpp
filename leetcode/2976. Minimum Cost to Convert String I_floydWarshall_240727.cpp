class Solution {
    using ll = long long;
    const int INF = 0x3f3f3f3f;
    int _cost[26][26];
public:
    ll minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        memset(_cost, 0x3f, sizeof _cost);
        for(int i = 0; i<26; ++i) _cost[i][i] = 0;
        for(int i = 0, n = changed.size(); i<n; ++i){
            int o = original[i]-'a', c = changed[i]-'a', tcost = cost[i];
            _cost[o][c] = min(_cost[o][c], tcost);
        }
        for(int mid = 0; mid<26; ++mid){
            for(int i = 0; i<26; ++i){
                for(int j = 0; j<26; ++j){
                    _cost[i][j] = min(_cost[i][j], _cost[i][mid] + _cost[mid][j]);
                }
            }
        }
        ll ret = 0;
        for(int i = 0, n = source.size(); i<n; ++i){
            int tcost = _cost[source[i]-'a'][target[i] - 'a'];
            if(tcost == INF) return -1;
            ret += tcost;
        }
        return ret;
    }
};
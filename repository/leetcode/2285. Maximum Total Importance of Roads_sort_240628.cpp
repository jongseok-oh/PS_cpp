class Solution {
    typedef long long ll;
public:
    ll maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> cnt(n);
        for(auto& road: roads){
            int a = road[0], b = road[1];
            ++cnt[a]; ++cnt[b];
        }
        sort(cnt.begin(), cnt.end());
        ll ret = 0;
        for(ll i = 0; i<n; ++i) ret += (i + 1) * cnt[i];

        return ret;
    }
};
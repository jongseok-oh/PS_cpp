class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int n = g.size(), m = s.size();

        int ret = 0;
        for(int i = 0, j = 0; i<n; ++i, ++j){
            while(j < m && s[j] < g[i]) j++;
            if(j >= m) break;
            else ++ret;
        }

        return ret;
    }
};
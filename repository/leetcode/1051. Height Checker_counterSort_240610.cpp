class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        vector<int> cnt(101), expect(n);
        for(int h : heights) ++cnt[h];
        for(int i = 1; i<101; ++i) cnt[i] += cnt[i-1];
        for(int i = n-1; i>=0; --i) expect[--cnt[heights[i]]] = heights[i];
        int ret = 0;
        for(int i = 0; i<n; ++i){
            if(heights[i] != expect[i]) ++ret;
        }
        return ret;
    }
};
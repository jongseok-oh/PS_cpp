class Solution {
    int sum[100000];
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();

        for(int i = 0; i<n; ++i) sum[i] = abs(s[i] - t[i]);

        int ret = 0, tsum = 0;
        for(int i = 0, j = 0; i<n; ++i){
            while(j<n && tsum + sum[j] <= maxCost) tsum += sum[j++];
            ret = max(ret, j - i);
            tsum -= sum[i];
        }
        return ret;
    }
};
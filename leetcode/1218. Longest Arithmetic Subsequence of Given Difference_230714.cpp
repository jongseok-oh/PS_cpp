class Solution {
    const int DIFF = 10000;
    int cnt[20001];
public:
    int longestSubsequence(vector<int>& arr, int d) {
        int ans = -1;

        for(int num: arr){
            if(num - d + DIFF < 0 || num - d + DIFF > 20000 ||
            (cnt[num - d + DIFF] == 0 && cnt[num + DIFF] == 0))
                cnt[num + DIFF] = 1;
            else if(cnt[num - d + DIFF] + 1 > cnt[num + DIFF])
                cnt[num + DIFF] = cnt[num - d + DIFF] + 1;
            
            ans = max(ans, cnt[num + DIFF]);
        }

        return ans;
    }
};
class Solution {
    int cnt[26];
public:
    int leastInterval(vector<char>& tasks, int n) {
        for(char c : tasks) ++cnt[c-'A'];
        int maxCnt = *max_element(cnt, cnt + 26);
        int maxCntCnt = count(cnt, cnt + 26, maxCnt);
        int ret = (n + 1) * (maxCnt-1)+ maxCntCnt;
        return max(ret, (int)tasks.size());
    }
};
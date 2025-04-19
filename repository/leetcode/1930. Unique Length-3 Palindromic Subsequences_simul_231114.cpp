class Solution {
    int start[26];
    int end[26];

    bool visit[26];
public:
    int countPalindromicSubsequence(string s) {
        memset(start, -1, sizeof start);

        int n = s.size();
        for(int i =0; i<n; ++i){
            int idx = s[i] - 'a';
            if(start[idx] == -1) start[idx] = i;
            end[idx] = i;
        }

        int ret = 0;

        for(int i = 0; i<26; ++i){
            if(start[i] == -1) continue;
            memset(visit, 0, sizeof visit);
            for(int t = start[i] + 1; t<end[i]; ++t){
                int idx = s[t] - 'a';
                if(!visit[idx]) visit[idx] = true, ++ret;
            }
        }

        return ret;
    }
};
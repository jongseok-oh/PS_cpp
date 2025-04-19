class Solution {
    int cnt[26];
    int idx[26];
public:
    int firstUniqChar(string s) {
        int n = s.size();
        for(int i = 0; i<n; ++i){
            int cIdx = s[i] - 'a';
            cnt[cIdx]++;
            idx[cIdx] = i;
        }

        int ret = 1e9;
        for(int i = 0; i<26; ++i)
            if(cnt[i] == 1) ret = min(ret, idx[i]);
        
        return ret==1e9?-1:ret;
    }
};
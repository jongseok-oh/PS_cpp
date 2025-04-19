class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> cnt(26);
        for(char c : s) ++cnt[c-'a'];

        int odd = 0, evenSum = 0;
        for(int i = 0; i<26; ++i){
            if(cnt[i]&1) ++odd;
            evenSum += cnt[i]/2;
        }

        if(odd > k) return false;
        return k - odd <= evenSum* 2;
    }
};
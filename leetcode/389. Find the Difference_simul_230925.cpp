class Solution {
    int cnt[26];
public:
    char findTheDifference(string s, string t) {
        for(auto& c: s) ++cnt[c-'a'];
        for(auto& c: t) --cnt[c-'a'];

        for(int i = 0; i<26; ++i)
            if(cnt[i]) return i + 'a';
        
        return '&';
    }
};
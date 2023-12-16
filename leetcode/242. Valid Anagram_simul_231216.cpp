class Solution {
    int cnt[26];
public:
    bool isAnagram(string s, string t) {
        if(s.size() > t.size()) swap(s, t);
        for(char c: s) ++cnt[c-'a'];
        for(char c: t) if(--cnt[c-'a'] < 0) return false;
        return true;
    }
};
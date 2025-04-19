class Solution {
    int cnt1[26], cnt2[26];
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;
        for(char c: word1) {++cnt1[c-'a'];}
        for(char c: word2) {++cnt2[c-'a'];}

        for(int i = 0; i<26; ++i)
            if(((bool)cnt1[i])^((bool)cnt2[i])) return false;

        sort(cnt1, cnt1 + 26, [&](int& a, int& b){return a > b;});
        sort(cnt2, cnt2 + 26, [&](int& a, int& b){return a > b;});

        for(int i = 0; i<26; ++i)
            if(cnt1[i] != cnt2[i]) return false;
        return true;
    }
};
class Solution {
    int sc[26];
public:
    int minSteps(string s, string t) {
        for(char c: s) sc[c-'a']++;
        for(char c: t) sc[c-'a']--;

        int ret = 0;
        for(int i = 0; i<26; ++i) ret += abs(sc[i]);
        return ret/2;
    }
};
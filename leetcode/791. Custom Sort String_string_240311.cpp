class Solution {
    int cnt[26];
public:
    string customSortString(string order, string s) {
        for(char c: s) cnt[c-'a']++;
        
        string ret = "";

        for(char c: order){
            ret += string(cnt[c-'a'], c);
            cnt[c-'a'] = 0;
        }

        for(int i = 0; i<26; ++i)
            if(cnt[i]) ret += string(cnt[i], i + 'a');
        
        return ret;
    }
};
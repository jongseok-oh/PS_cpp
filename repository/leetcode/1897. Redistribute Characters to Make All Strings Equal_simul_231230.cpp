class Solution {
    int cnt[26];
public:
    bool makeEqual(vector<string>& words) {
        for(auto& s: words) for(char& c: s)
            ++cnt[c-'a'];
        
        int n = words.size();
        for(int i = 0; i<26; ++i)
            if(cnt[i]%n) return false;
        
        return true;
    }
};
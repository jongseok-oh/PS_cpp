class Solution {
    bool isPrefix(string& word, string& pref){
        int n = word.size(), m = pref.size();
        if(n < m) return false;
        for(int i = 0; i<m; ++i){
            if(word[i] != pref[i]) return false;
        }
        return true;
    }
public:
    int prefixCount(vector<string>& words, string pref) {
        int ret = 0;
        for(string& word : words){
            if(isPrefix(word, pref)) ++ret;
        }
        return ret;
    }
};
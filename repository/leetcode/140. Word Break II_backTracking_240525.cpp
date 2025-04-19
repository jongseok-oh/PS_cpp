class Solution {
    unordered_set<string> dict;

    string combine(vector<string>& temp){
        string ret = "";
        for(int i = 0, n = temp.size(); i<n; ++i){
            ret += temp [i];
            if(i != n-1) ret += " ";
        }
        return ret;
    }
    void solve(int idx, string& s, vector<string> temp, vector<string>& ret){
        if(idx == s.size()){
            ret.push_back(combine(temp));
            return;
        }

        string t;
        for(int i = 0; i<10 && idx + i < s.size(); ++i){
            t += s[idx + i];
            if(dict.count(t)){
                vector<string> copyTemp = temp;
                copyTemp.push_back(t);
                solve(idx + i + 1, s, copyTemp, ret);
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(string& s : wordDict) dict.insert(s);
        vector<string> ret;
        solve(0, s, {}, ret);
        return ret;
    }
};
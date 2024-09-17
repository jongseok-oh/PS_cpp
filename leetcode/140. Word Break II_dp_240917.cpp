class Solution {
    vector<string> dp[20];
    vector<string> solve(int idx, const string& s,unordered_set<string>& wordSet){
        if(idx == s.size()) return {};
        
        auto& ret = dp[idx];
        if(ret.size()) return ret;

        string temp = "";
        for(int i = idx; i<s.size(); ++i){
            temp.push_back(s[i]);
            if(wordSet.count(temp)){
                auto t = solve(i + 1, s, wordSet);
                if(t.empty()) ret.emplace_back(temp);
                else if(t[0] != "-"){
                    for(string& str : t){
                        string converted = temp;
                        converted += " ";
                        converted += str;
                        ret.emplace_back(converted);
                    }
                }
            }
        }

        if(ret.size() == 0) ret = {"-"};
        return ret;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        auto ret = solve(0, s, wordSet);
        if(ret[0] == "-") return {};
        return ret;
    }
};
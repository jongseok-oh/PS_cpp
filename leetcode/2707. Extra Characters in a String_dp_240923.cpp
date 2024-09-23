class Solution {
    int dp[50];
    int solve(int idx,const string& s, const set<string>& dict){
        int n = s.size();
        if(idx == n) return 0;

        int& ret = dp[idx];
        if(ret != -1) return ret;

        ret = 1 + solve(idx+1,s,dict);

        string temp = "";
        for(int i = idx; i<n; ++i){
            temp.push_back(s[i]);
            if(dict.count(temp)){
                ret = min(ret, solve(i+1,s,dict));
            }
        }

        return ret;
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        memset(dp, -1, sizeof dp);
        set<string> dicSet(dictionary.begin(), dictionary.end());
        return solve(0,s,dicSet);
    }
};
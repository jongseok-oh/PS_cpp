class Solution {
    bool palindrome[16][16];
    vector<vector<string>> dp[16];
    
    vector<vector<string>> solve(int start, string& s){
        if(start == s.size()) return {{}};
        auto& ret = dp[start];
        if(ret.size()) return ret;

        for(int i = start; i<s.size(); ++i){
            if(palindrome[start][i]){
                auto t = solve(i + 1, s);
                for(auto& vec: t) vec.push_back(s.substr(start, i - start + 1));
                ret.insert(ret.end(), t.begin(), t.end());
            }
        }
        return ret;
    }
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();

        for(int i = 0; i<n; ++i) {
            palindrome[i][i] = true;
            if(i != n -1 && s[i] == s[i+1]){
                palindrome[i][i+1] = true;
            }
        }

        for(int diff = 2; diff<n; ++diff) for(int i = 0; i<n-diff; ++i){
            int j = i + diff;
            if(s[i] == s[j] && palindrome[i + 1][j-1]){
                palindrome[i][j] = true;
            }
        }

        auto ret = solve(0,s);
        for(auto& vec: ret) reverse(vec.begin(), vec.end());
        return ret;
    }
};
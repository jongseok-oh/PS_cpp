class Solution {
    vector<int> failureFunction(string& s){
        int n = s.size();
        vector<int> pi(n);
        
        for (int i = 1; i < n; i++) {
            int length = pi[i - 1];
            while (length > 0 && s[i] != s[length]) {
                length = pi[length - 1];
            }
            if (s[i] == s[length]) {
                length++;
            }
            pi[i] = length;
        }
        
        return pi;
    }
    vector<bool> kmp(string& s, vector<int>& pi, string& pattern){
        int n = s.size(), m = pattern.size();
        
        vector<bool> ret(n);
        for(int i = 0, length = 0, lastMatch = 0; i<n; ++i){
            while(length > 0 && s[i] != pattern[length]){
                length = pi[length - 1];
            }
            if (s[i] == pattern[length]) {
                length++;
                if(length == m) {
                    for(int j = max(lastMatch, i - length + 1); j<=i; ++j){
                        ret[j] = true;
                    }
                    length = pi[length - 1];
                    lastMatch = i;
                }
            }
        }
        return ret;
    }
public:
    int countCells(vector<vector<char>>& grid, string pattern) {
        int n = grid.size(), m = grid[0].size();
        
        string horizontal = "";
        for(auto& row : grid) for(char c : row){
            horizontal.push_back(c);
        }
        
        string vertical = "";
        for(int i = 0; i<m; ++i) for(int j = 0; j<n; ++j){
            vertical.push_back(grid[j][i]);
        }
        
        vector<int> pi = failureFunction(pattern);
        
        vector<bool> hMatch = kmp(horizontal, pi, pattern);
        vector<bool> vMatch = kmp(vertical, pi, pattern);
        
        int ret = 0;
        for(int i = 0; i<n; ++i) for(int j = 0; j<m; ++j){
            if(hMatch[i*m + j] && vMatch[i + j *n]) ++ret;
        }
        
        return ret;
    }
};
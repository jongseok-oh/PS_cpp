class Solution {
    bool visit[20][20];
    bool solve(int i, int j, const string& s, const string& p){
        if(i >= s.size() && j >= p.size()) return true;
        if(j >= p.size()) return false;
        
        if(visit[i][j]) return false;
        visit[i][j] = true;

        if(j < p.size() -1 && p[j+1] == '*'){
            if(solve(i, j + 2, s, p)) return true;
            if(i<s.size() && (s[i] == p[j] || p[j] == '.')){
                if(solve(i + 1, j, s, p) || solve(i + 1, j + 2, s, p)){
                    return true;
                }
            }
        }else if(i<s.size() && (s[i] == p[j] || p[j] == '.') && solve(i + 1, j + 1, s, p)){
            return true;
        }

        return false;
    }
public:
    bool isMatch(string s, string p) {
        return solve(0,0,s,p);
    }
};
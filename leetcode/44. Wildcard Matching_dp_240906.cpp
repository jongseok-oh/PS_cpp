class Solution {
    bool visit[2000][2000];
    
    bool solve(int i, int j, const string& s, const string& p){
        if(i >= s.size() && j >= p.size()) return true;
        if(j >= p.size()) return false;
        
        if(visit[i][j]) return false;
        visit[i][j] = true;
        // i's condition can be >= s.size();
        
        if(p[j] == '*'){
            // skip *
            if(solve(i, j + 1, s, p)) return true;

            if(i<s.size()){
                // use once
                if(solve(i + 1, j + 1, s, p)) return true;
                // use more than once
                if(solve(i + 1, j, s, p)) return true;
            }
        }else{
            if(i<s.size() && (s[i] == p[j] || p[j] == '?') && solve(i + 1, j + 1, s, p)){
                return true;
            }
        }

        return false;
    }
public:
    bool isMatch(string s, string p) {
        return solve(0,0,s,p);
    }
};
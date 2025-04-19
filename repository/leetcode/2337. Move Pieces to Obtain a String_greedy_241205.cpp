class Solution {
public:
    bool canChange(string start, string target) {
        int n = target.size();
        string trimS, trimT;
        for(int i = 0; i<n; ++i){
            char s = start[i], t = target[i];
            if(s != '_') trimS.push_back(s);
            if(t != '_') trimT.push_back(t);
        }
        if(trimS != trimT) return false;

        for(int i = 0, j=0; i<n; ++i){
            char t = target[i];
            if(t == '_') continue;
            while(j < n && start[j] == '_') ++j;
            if(j == n) return false;
            char s = start[j];

            if(s != t) return false;
            if((s == 'R' && i < j) || (s == 'L' && i > j)) return false;
            ++j;
        }
        return true;
    }
};
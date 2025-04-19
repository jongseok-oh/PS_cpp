class Solution {
    int visit1[256], visit2[256];
public:
    bool isIsomorphic(string s, string t) {
        memset(visit1, -1, sizeof visit1);
        memset(visit2, -1, sizeof visit2);

        int n = s.size();
        for(int i = 0; i<n; ++i){
            char c1 = s[i], c2 = t[i];
            if(!(visit1[c1] == -1 && visit2[c2] == -1)){
                if(visit1[c1] != visit2[c2]) return false;
            }
            visit1[c1] = i; visit2[c2] = i;
        }
        
        return true;
    }
};
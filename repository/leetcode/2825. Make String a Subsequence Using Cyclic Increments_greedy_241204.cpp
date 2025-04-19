class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        if(n < m) return false;

        for(int i = 0, j = 0; j<m; ++j, ++i){
            int c1 = str1[i] - 'a', c2 = str2[j] - 'a';
            while(i<n && c1 != c2 && ((c1+1)%26) != c2){
                c1 = str1[++i] - 'a';
            }
            if(i == n) return false;
        }

        return true;
    }
};
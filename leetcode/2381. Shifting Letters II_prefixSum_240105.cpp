class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> shiftFlag(n+1);

        for(auto& shift : shifts){
            int s = shift[0], e = shift[1], d = shift[2];
            
            int inc = (d == 0? -1:1);
            shiftFlag[s] = (shiftFlag[s] + inc + 26) % 26;
            shiftFlag[e + 1] = (shiftFlag[e + 1] -inc + 26) % 26;
        }

        for(int i = 0; i<n; ++i){
            s[i] = (s[i] - 'a' + shiftFlag[i]) % 26 + 'a';
            shiftFlag[i + 1] += shiftFlag[i];
        }

        return s;
    }
};
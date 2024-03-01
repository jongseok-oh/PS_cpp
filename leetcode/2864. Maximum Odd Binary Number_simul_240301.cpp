class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int oneCnt = 0;
        for(char c: s) if(c == '1') oneCnt++;

        string ret;
        for(int i = 0; i<oneCnt-1; ++i) ret += "1";
        for(int  i = 0; i<s.size()-oneCnt; ++i) ret += "0";
        ret+="1";
        
        return ret;
    }
};
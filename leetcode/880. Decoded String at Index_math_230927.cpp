class Solution {
    typedef long long ll;

    bool isNum(char c){
        return c >= '2' && c <= '9';
    }
public:
    string decodeAtIndex(string s, int k) {
        ll len = 0;
        
        for(char& c: s)
            if(isNum(c)) len *= c - '0';
            else ++len;
        
        for(auto it = s.rbegin(); it != s.rend(); ++it){
            if(isNum(*it)){
                len /= *it - '0';
                k %= len;
            }else{
                if(!k || k == len) return string("") + *it;
                --len;
            }
        }

        return "";
    }
};
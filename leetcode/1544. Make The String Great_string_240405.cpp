class Solution {
    bool isSame(char a, char b){
        return a-'a' == b - 'A' || a-'A' == b - 'a';
    }
public:
    string makeGood(string s) {
        vector<char> st;

        for(int i = 0, n = s.size(); i<n; ++i){
            if(st.empty() || !isSame(st.back(), s[i])){
                st.push_back(s[i]);
            }else st.pop_back();
        }

        string ret;
        for(char c: st) ret += c;
        return ret;
    }
};
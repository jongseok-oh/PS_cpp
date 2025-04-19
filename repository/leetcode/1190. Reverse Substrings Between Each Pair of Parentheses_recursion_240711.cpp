class Solution {
public:
    string reverseParentheses(string s) {
        string ret = "";
        for(int i = 0, n = s.size(); i<n; ++i){
            if(s[i] == '('){
                ++i;
                int cnt = 1, j = i;
                while(j < n && cnt){
                    if(s[j] == '(') ++cnt;
                    else if(s[j] == ')') --cnt;
                    ++j;
                }
                string t = reverseParentheses(s.substr(i, j - i - 1));
                reverse(t.begin(), t.end());
                ret += t;
                i = j-1;
            }else ret.push_back(s[i]);
        }
        return ret;
    }
};
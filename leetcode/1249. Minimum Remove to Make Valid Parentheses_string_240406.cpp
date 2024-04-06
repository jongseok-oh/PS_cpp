class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int cnt = 0, n = s.size();
        for(int i = 0; i<n; ++i){
            char& c = s[i];
            if(c == ')'){
                if(cnt <= 0) c = '-';
                else --cnt;
            }else if(c == '(') cnt++;
        }

        int i = n-1;
        while(cnt && i >=0){
            if(s[i] == '(') {s[i] = '-'; --cnt;}
            --i;
        }

        string ret;
        for(int i = 0; i<n; ++i)
            if(s[i] != '-') ret += s[i];
        return ret;
    }
};
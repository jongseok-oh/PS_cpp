class Solution {
public:
    int maxDepth(string s) {
        int ret = 0, cnt = 0;
        for(char c: s){
            if(c == '(') ++cnt;
            else if(c == ')') ret = max(ret, cnt--);    
        }
        return ret;
    }
};
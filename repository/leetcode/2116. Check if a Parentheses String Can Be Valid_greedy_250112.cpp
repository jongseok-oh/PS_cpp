class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if(n&1) return false;

        int noLock = 0, left = 0;
        for(int i = 0; i<n; ++i){
            if(locked[i] == '0') ++noLock;
            else if(s[i] == '(') ++left;
            else if(s[i] == ')'){
                if(left > 0) --left;
                else{
                    if(noLock > 0) --noLock;
                    else return false;
                }
            }
        }

        int right = 0;
        noLock = 0;
        for(int i = n-1; i>=0; --i){
            if(locked[i] == '0') ++noLock;
            else if(s[i] == ')') ++right;
            else if(s[i] == '('){
                if(right > 0) --right;
                else{
                    if(noLock > 0) --noLock;
                    else return false;
                }
            }
        }

        return true;
    }
};
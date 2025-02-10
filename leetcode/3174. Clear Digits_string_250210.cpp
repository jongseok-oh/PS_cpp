class Solution {
    bool isDigit(char c){
        return c >= '0' && c <= '9';
    }
public:
    string clearDigits(string s) {
        string stack;
        for(char c : s){
            if(isDigit(c)){
                if(stack.size()) stack.pop_back();
            }else stack.push_back(c);
        }
        return stack;
    }
};
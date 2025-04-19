class Solution {
    vector<string> split(string subExp){
        vector<string> exps;
        int n = subExp.size();
        for(int start = 0, length = 1; start<n;){
            if(subExp[start] == 'f' || subExp[start] == 't'){
                exps.push_back(subExp.substr(start, 1));
                start += 2;
                continue;
            }
            length = 3;
            int left = 1;
            while(start + length <= n && left > 0){
                char t = subExp[start + length - 1];
                if(t == '(') ++left;
                else if(t == ')') --left;
                ++length;
            }
            exps.push_back(subExp.substr(start, length - 1));
            start += length;
            length = 1;
        }
        return exps;
    }
public:
    bool parseBoolExpr(string expression) {
        if(expression.size() == 1) return expression == "t";
        vector<string> subExps = split(expression.substr(2, expression.size()-3));
        
        char oper = expression[0];
        if(oper == '!') return !parseBoolExpr(subExps[0]);
        else if(oper == '&'){
            bool ret = true;
            for(string& exp : subExps){
                ret &= parseBoolExpr(exp);
            }
            return ret;
        }
        else {
            bool ret = false;
            for(string& exp : subExps){
                ret |= parseBoolExpr(exp);
            }
            return ret;
        }
    }
};
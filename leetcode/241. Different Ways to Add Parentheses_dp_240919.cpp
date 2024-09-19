class Solution {
    vector<int> dp[20][20];

    int calc(int num1, int num2, char oper){
        if(oper == '+') return num1 + num2;
        else if(oper == '-') return num1 - num2;
        else return num1 * num2;
    }

    vector<int> solve(int i , int j, const string& exp){
        if(j == i || j - i == 1)
            return {stoi(exp.substr(i, j - i + 1))};

        auto& ret = dp[i][j];
        if(ret.size()) return ret;

        for(int idx = i; idx<j; ++idx){
            char oper = exp[idx];
            if(oper == '-' || oper == '+' || oper == '*'){
                vector<int> left = solve(i, idx - 1, exp);
                vector<int> right = solve(idx + 1, j, exp);

                for(int num1 : left) for(int num2 : right){
                    ret.push_back(calc(num1,num2, oper));
                }
            }
        }

        return ret;
    }
public:
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();
        if(n == 1 || n == 2){
            return {stoi(expression)};
        }
        return solve(0, n -1, expression);
    }
};
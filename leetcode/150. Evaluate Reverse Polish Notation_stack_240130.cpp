class Solution {
    bool isOper(string& t){
        return t == "+" || t == "-" || t == "*" || t == "/";
    }

    int calc(int n1, int n2, string op){

        if(op == "+") return n1 + n2;
        if(op == "-") return n1 - n2;
        if(op == "*") return n1 * n2;
        if(op == "/") return n1 / n2;
        return 1e9;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;

        for(string& token: tokens){
            if(isOper(token)){
                int n1 = nums.top(); nums.pop();
                int n2 = nums.top(); nums.pop();
                int cal = calc(n2,n1,token);
                nums.push(cal);
            }else nums.push(stoi(token));
        }
        return nums.top();
    }
};
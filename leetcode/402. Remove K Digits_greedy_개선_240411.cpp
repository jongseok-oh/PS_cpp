class Solution {
public:
    string removeKdigits(string num, int k) {
        string ret = "";

        for(char c: num){
            while(ret.size() && k && ret.back() > c){
                --k;
                ret.pop_back();
            }
            if(ret.size() || c != '0') ret.push_back(c);
        }
        while(ret.size() && k--) ret.pop_back();

        return ret.size()?ret:"0";
    }
};
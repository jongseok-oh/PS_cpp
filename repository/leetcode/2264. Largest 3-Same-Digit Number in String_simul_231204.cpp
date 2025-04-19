class Solution {
public:
    string largestGoodInteger(string num) {
        string ret = "";
        int sameCnt = 1;
        for(int i = 1; i<num.size(); ++i){
            if(num[i] == num[i-1]) ++sameCnt;
            else sameCnt = 1;

            if(sameCnt == 3){
                string good = num.substr(i-2, 3);
                if(good > ret) ret = good;
                sameCnt = 1;
            }
        }

        return ret;
    }
};
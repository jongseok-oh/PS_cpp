class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";

        string str = countAndSay(n-1), rle = "";
        for(int i = 0, len = str.size(); i<len;){
            int cnt = 1;
            char c = str[i++];
            while(i<len && c == str[i]){
                ++cnt;
                ++i;
            }
            rle += to_string(cnt) + c;
        }

        return rle;
    }
};
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ret = 0; 
        for(string& det : details){
            if((det[11] - '0') * 10 + (det[12] - '0') > 60){
                ++ret;
            }
        }
        return ret;
    }
};
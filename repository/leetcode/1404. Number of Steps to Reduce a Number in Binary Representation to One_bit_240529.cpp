class Solution {
public:
    int numSteps(string s) {
        int cnt = 0, idx = s.size() -1;
        while(idx != 0 || s[idx] != '1'){
            int num = s[idx] - '0';
            if(num&1){
                s[idx]++;
            }else{
                if(idx != 0){
                    s[--idx] += num/2;
                }else{
                    s[idx] = num/2 + '0';
                }
            }
            ++cnt;
        }
        return cnt;
    }
};
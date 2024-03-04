class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());

        int ret = 0, score = 0;
        int left = 0, right = tokens.size()-1;
        while(left <= right){
            if(power >= tokens[left]){
                power -= tokens[left++];
                ++score;
            }else{
                if(score > 0){
                    --score;
                    power += tokens[right--];
                }else break;
            }
            ret = max(ret, score);
        }

        return ret;
    }
};
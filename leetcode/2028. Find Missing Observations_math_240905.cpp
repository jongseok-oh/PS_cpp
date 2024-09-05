class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int mSum = 0, m = rolls.size();
        for(int roll : rolls){
            mSum += roll;
        }
        int nSum = mean * (n + m) - mSum;
        if(nSum < n) return {};
        
        int calc = nSum/n, remain = nSum%n;
        if(calc > 6 || (calc == 6 && remain > 0)) return {};

        vector<int> result(n);
        for(int i = 0; i<n; ++i){
            int& ret = result[i];
            if(remain > 0){
                ret = calc + 1;
                --remain;
            }else ret = calc;
        }
        return result;
    }
};
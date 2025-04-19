class Solution {
public:
    string removeKdigits(string num, int k) {
        string ret;

        int n = num.size(), start = 0;

        while(k){
            char _min = num[start];
            int minIdx = start;

            for(int i = start; i<start + k + 1; i++){
                if(i == n) {minIdx = n; break;}
                if(_min > num[i]){
                    _min = num[i]; minIdx = i;
                }
                if(_min == '0') break;
            }

            if(minIdx == n) {start = n; break;}

            ret += _min;
            k -= minIdx - start;
            start = minIdx + 1;
        }

        ret += num.substr(start);

        int noZeroIdx = 0;
        while(ret[noZeroIdx] == '0') noZeroIdx++;

        ret = ret.substr(noZeroIdx);
        return ret.size()?ret:"0";
    }
};
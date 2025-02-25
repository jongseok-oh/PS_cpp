class Solution {
    const int MOD = 1e9 + 7;
public:
    int numOfSubarrays(vector<int>& arr) {
        int evenSumCnt = 0, oddSumCnt = 0;
        if(arr[0]&1) oddSumCnt = 1;
        else evenSumCnt = 1;

        int ret = oddSumCnt;
        for(int i = 1, n = arr.size(); i<n; ++i){
            int num = arr[i];
            if(num & 1){
                int prevEvenSumCnt = evenSumCnt;
                int prevOddSumCnt = oddSumCnt;

                oddSumCnt = prevEvenSumCnt + 1;
                evenSumCnt = prevOddSumCnt;
            }else{
                evenSumCnt = evenSumCnt + 1;
            }
            ret = (ret + oddSumCnt) % MOD;
        }

        return ret;
    }
};
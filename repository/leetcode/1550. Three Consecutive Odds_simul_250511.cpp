class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int conOddCnt = 0;
        for(int num : arr){
            if(num&1){
                if(++conOddCnt == 3) return true;
            }else conOddCnt = 0;
        }
        return false;
    }
};
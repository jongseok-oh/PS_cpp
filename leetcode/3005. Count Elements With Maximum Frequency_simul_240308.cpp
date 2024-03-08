class Solution {
    int cnt[101];
public:
    int maxFrequencyElements(vector<int>& nums) {
        for(int num: nums) ++cnt[num];

        int maxCnt = -1, sum = 0;
        for(int i = 1; i<=100; ++i){
            if(cnt[i] > maxCnt){
                maxCnt = cnt[i];
                sum = maxCnt;
            }else if(cnt[i] == maxCnt) sum += maxCnt;
        }

        return sum;
    }
};
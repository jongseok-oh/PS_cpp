class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> bitCnt(27);
        for(int candi : candidates){
            for(int i = 0; i<27; ++i){
                bitCnt[i] += (candi & (1<<i)) > 0;
            }
        }
        return *max_element(bitCnt.begin(), bitCnt.end());
    }
};
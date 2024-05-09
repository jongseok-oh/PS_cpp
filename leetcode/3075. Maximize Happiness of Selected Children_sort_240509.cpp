class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), [&](int& a, int& b){
            return a > b;
        });

        int minusHappy = 0;
        long long ret = 0;

        for(int i = 0; i<k; ++i){
            int happy = happiness[i] - minusHappy;
            if(happy <= 0) break;
            ret += happy; ++minusHappy;
        }

        return ret;
    }
};
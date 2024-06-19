class Solution {
    bool check(int day, int m, int k,vector<int>& bloomDay){
        int range = 0, ret = 0;
        for(int bloom: bloomDay){
            if(bloom > day){
                ret += range / k;
                range = 0;
            }else ++range;
        }
        ret += range / k;
        return ret >= m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size() < (long long)m * k) return -1;
        int _max = *max_element(bloomDay.begin(), bloomDay.end());

        int low = 0, high = _max+1;
        while(low + 1 < high){
            int mid = (low + high) >>1;
            if(check(mid, m, k, bloomDay)) high =mid;
            else low = mid;
        }

        return (high==_max +1)?-1:high;
    }
};
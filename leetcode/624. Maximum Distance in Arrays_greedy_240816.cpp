class Solution {
    int getMax(int idx, vector<vector<int>>& arrays){
        return arrays[idx].back();
    }
    int getMin(int idx, vector<vector<int>>& arrays){
        return arrays[idx][0];
    }
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int fmin = -1, smin = -1, fmax = -1 , smax = -1;
        for(int i = 0; i<arrays.size(); ++i){
            int _min = getMin(i, arrays), _max = getMax(i, arrays);
            if(fmin == -1 || getMin(fmin, arrays) > _min){
                smin = fmin;
                fmin = i;
            }else if(smin == -1 || getMin(smin, arrays) > _min){
                smin = i;
            }
            if(fmax == -1 || getMax(fmax, arrays) < _max){
                smax = fmax;
                fmax = i;
            }else if(smax == -1 || getMax(smax, arrays) > _min){
                smax = i;
            }
        }
        int ret = -1;
        if(fmin != fmax) ret = getMax(fmax, arrays) - getMin(fmin, arrays);
        else ret = max(getMax(fmax, arrays) - getMin(smin, arrays), getMax(smax, arrays) - getMin(fmin, arrays));
        return ret;
    }
};
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = grumpy.size(), sum = 0;
        for(int i =0; i<n; ++i){
            sum += grumpy[i]?0:customers[i];
        }
        int i = 0;
        for(; i<minutes; ++i){
            sum += grumpy[i]?customers[i]:0;
        }
        int ret = sum;
        for(; i<n; ++i){
            if(grumpy[i-minutes]) sum -= customers[i-minutes];
            if(grumpy[i]) sum += customers[i];
            ret = max(ret, sum);
        }
        return ret;
    }
};
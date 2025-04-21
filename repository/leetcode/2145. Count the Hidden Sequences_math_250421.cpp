class Solution {
    using ll = long long;
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        ll _min = 0, _max = 0, prefixSum = 0;
        for(int diff : differences){
            prefixSum += diff;
            _min = min(prefixSum, _min);
            _max = max(prefixSum, _max);
        }
        
        if(upper - lower < _max - _min) return 0;
        return (upper - lower) - (_max - _min) + 1;
    }
};
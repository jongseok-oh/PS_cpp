class Solution {
public:
    double average(vector<int>& salary) {
        int _min = 1e9, _max = -1;
        int sum = 0;

        for(int i = 0, len = salary.size(); i<len; i++){
            int num = salary[i];
            sum += num;
            if(_min > num) _min = num;
            if(_max < num) _max = num;
        }
        return ((double)sum - _min - _max)/(salary.size()-2);
    }
};
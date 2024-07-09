class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& c) {
        int n = c.size();
        double sum = c[0][1], cur = c[0][1] + c[0][0];
        for(int i = 1; i<n; ++i){
            auto& cut = c[i];
            int arr = cut[0], time = cut[1];
            if(cur > arr) {
                sum += cur - arr + time;
                cur += time;
            }else{
                sum += time;
                cur = arr + time;
            }
            
        }
        return sum/n;
    }
};
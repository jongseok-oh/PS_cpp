class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<double> time(n);

        for(int i =0; i<n; ++i)
            time[i] = (double)dist[i]/speed[i];
        
        sort(time.begin(), time.end());

        for(int i = 0; i<n; ++i){
            if(i>=time[i]) return i;
        }

        return n;
    }
};
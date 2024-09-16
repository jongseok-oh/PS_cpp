class Solution {
    int convert2Min(string& time){
        int hour = stoi(time.substr(0,2));
        int minute = stoi(time.substr(3));
        return hour * 60 + minute;
    }
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> minutes(n);
        for(int i = 0; i<n; ++i){
            minutes[i] = convert2Min(timePoints[i]);
        }
        sort(minutes.begin(), minutes.end());
        
        int minTimeDiff = 1e9, MOD = 60 * 24;
        for(int i = 0; i<n; ++i){
            int diff = (minutes[(i+1)%n] - minutes[i] + MOD) % MOD;
            minTimeDiff = min(minTimeDiff, diff);
        }

        return minTimeDiff;
    }
};
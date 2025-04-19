class Solution {

    double calc(vector<int>& dist, int speed, int n){
        int time = 0;

        for(int i = 0; i<n-1; i++){
            time += (dist[i] + speed-1) / speed;
        }
        return (double)dist[n-1] / speed + time;
    }

public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if(hour <= n - 1) return -1;

        int low = 0, high = 1e9;

        while(low + 1 < high){
            int mid = (low + high)>>1;

            double time = calc(dist, mid, n);

            if(time <= hour) high = mid;
            else low = mid;
        }

        return high;
    }
};
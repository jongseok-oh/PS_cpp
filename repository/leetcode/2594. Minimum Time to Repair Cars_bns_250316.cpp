class Solution {
    using ll = long long;
    ll maxRepairCars(ll time, vector<int>& ranks){
        ll cars = 0;
        for(int r : ranks){
            cars += floor(sqrt(time/r));
        }
        return cars;
    }
public:
    ll repairCars(vector<int>& ranks, int cars) {
        ll low = 0, high = 1e14;
        while(low + 1 < high){
            ll mid = (low + high)>>1;
            if(maxRepairCars(mid, ranks) >= cars){
                high = mid;
            }else low = mid;
        }
        return high;
    }
};
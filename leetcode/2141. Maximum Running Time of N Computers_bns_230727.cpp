typedef long long ll;

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        ll sum = 0;

        for(int b: batteries) sum += b;

        ll low = 1, high = sum/n + 1;

        while(low + 1 < high){
            ll mid = (low + high) >>1;

            ll tSum = 0;

            for(int b: batteries) tSum += min((ll)b, mid);

            if(tSum < mid * n) high = mid;
            else low = mid;
        }

        return low;
    }
};
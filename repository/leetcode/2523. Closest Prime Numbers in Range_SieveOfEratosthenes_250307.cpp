class Solution {
    vector<int> getPrimes(int _max){
        vector<bool> visit(_max + 1);
        vector<int> ret;
        for(int i = 2, end = sqrt(_max); i<=end; ++i){
            if(visit[i]) continue;

            for(int j = i * i; j <= _max; j += i){ 
                visit[j] = true;
            }
        }

        for(int i = 2; i<=_max; ++i){
            if(!visit[i]) ret.push_back(i);
        }
        
        return ret;
    }
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> primes = getPrimes(right);

        int minDiff = 1e9;
        vector<int> ret = {-1, -1};
        auto start = lower_bound(primes.begin(), primes.end(), left);
        if(start == primes.end()) return ret;
        
        auto end = upper_bound(primes.begin(), primes.end(), right);
        for(auto it = start; it + 1 != end; ++it){
            int num1 = *it, num2 = *(it + 1);
            if(num2 - num1 < minDiff){
                minDiff = num2 - num1;
                ret[0] = num1;
                ret[1] = num2;
            }
        }

        return ret;
    }
};
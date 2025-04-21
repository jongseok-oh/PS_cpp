class Solution {
    const int MOD = 1e9 + 7;
    using ll = long long;

    vector<int> getPrimes(int _max){
        int n = sqrt(_max);
        vector<bool> prime(_max + 1, true);
        for(int i = 2; i <= n; ++i){
            if(prime[i]){
                for(int j = i + i; j<=_max; j += i){
                    prime[j] = false;
                }
            }
        }

        vector<int> primes;
        for(int i = 2; i <= _max; ++i){
            if(prime[i]) primes.push_back(i);
        }
        
        return primes;
    }
    vector<vector<int>> getExponentOfFactorization(int _max){
        int n = sqrt(_max);
        vector<int> primes = getPrimes(_max);

        vector<vector<int>> eof(_max + 1);
        for(int i = 2; i<=_max; ++i){
            int x = i;
            for(int prime : primes){ 
                if(x % prime == 0){
                    int cnt = 0;
                    while(x > 1 && x % prime == 0){
                        ++cnt;
                        x /= prime;
                    }
                    eof[i].push_back(cnt);
                }
                if(x == 1) break;
            }
        }

        return eof;
    }
    vector<vector<int>> combinationTriangle(int n, int k){
        vector<vector<int>> nCr(n + k + 1, vector<int>(k + 1));
        nCr[0][0] = 1;

        for (int i = 1; i <=n + k; i++) {
            nCr[i][0] = 1;
            for (int j = 1; j <= min(i, k); j++) {
                nCr[i][j] = (nCr[i - 1][j] + nCr[i - 1][j - 1]) % MOD;
            }
        }

        return nCr;
    }
public:
    int idealArrays(int n, int maxValue) {
        vector<vector<int>> eof = getExponentOfFactorization(maxValue);
        vector<vector<int>> nCr = combinationTriangle(n, 16);

        int ans = 0;
        for(int i = 1; i<=maxValue; ++i){
            ll mult = 1;
            for(int p : eof[i]){
                mult = mult * nCr[n + p - 1][p] % MOD;
            }
            ans = (ans + mult) % MOD;
        }

        return ans;
    }
};
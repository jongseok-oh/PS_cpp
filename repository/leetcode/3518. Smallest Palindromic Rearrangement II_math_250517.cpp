class Solution {
    const int MAX_K = 1e6 + 1;
    using ll = long long;
    
    int nCr(int n, int r){
        if(r > n - r) r = n - r;
        
        ll ret = 1;
        for(int i = 0; i<r; ++i){
            ret *= (n - i);
            ret /= i + 1;
            if(ret >= MAX_K) return MAX_K;
        }
        return ret;
    }
    int permutCnt(int tot, vector<int>& cnt){
        ll ret = 1;
        for(int i = 0; i<26; ++i){
            if(!cnt[i]) continue;
            ret *= nCr(tot, cnt[i]);
            if(ret >= MAX_K) return MAX_K;
            
            tot -= cnt[i];
        }

        return ret;
    }
public:
    string smallestPalindrome(string s, int k) {
        int n = s.size();
        vector<int> cnt(26);

        for(char c : s) ++cnt[c -'a'];
        
        char center = '-';
        for(int i = 0; i<26; ++i){
            if(cnt[i] & 1) center = i + 'a';
            cnt[i] /= 2;
        }

        string ret(n, ' ');
        for(int i = 0; i<n/2; ++i){
            for(int j = 0; j<26; ++j){
                if(!cnt[j]) continue;
                --cnt[j];

                int pCnt = permutCnt(n/2 - i - 1, cnt);
                if(pCnt >= k){
                    ret[i] = j + 'a';
                    ret[n - i - 1] = j + 'a';
                    break;
                }else {
                    ++cnt[j]; k -= pCnt;
                }
            }
        }
        if(n & 1) ret[n/2] = center;

        return ret[0] == ' '?"":ret;
    }
};
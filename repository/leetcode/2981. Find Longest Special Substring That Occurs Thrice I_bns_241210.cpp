class Solution {
    vector<int> cnt[26];
    void insert(vector<int>& ref, int len){
        ref.push_back(len);
    }

    bool check(vector<int>& ref, int len){
        int cnt = 0;
        for(int r : ref){
            if(r >= len) cnt += r - len + 1;
        }
        return cnt >= 3;
    }
public:
    int maximumLength(string s) {
        char prev = s[0];
        int len = 1;
        for(int i = 1, n = s.size(); i<n; ++i){
            if(prev == s[i]){
                ++len;
            }else {
                insert(cnt[prev-'a'], len);
                len = 1;
                prev = s[i];
            }
        }
        insert(cnt[prev-'a'], len);
        
        int ret = 0;
        for(int i = 0; i<26; ++i){
            if(cnt[i].size()){
                int low = 0, high = 51;
                while(low + 1 < high){
                    int mid = (low + high)>>1;
                    if(check(cnt[i], mid)){
                        low = mid;
                    }else high = mid;
                }
                ret = max(ret, low);
            }
        }

        return ret?ret:-1;
    }
};
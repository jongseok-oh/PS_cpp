class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        int cnt[3] = {};
        for(char c : s) ++cnt[c-'a'];
        for(int i = 0; i<3; ++i){
            if(cnt[i] < k) return -1;
        }

        int maxWindow = 0;
        int window[3] = {};
        for(int l = 0, r = 0; r<n; ++r){
            ++window[s[r]-'a'];

            while(l<=r
            &&(cnt[0] - window[0] < k
            || cnt[1] - window[1] < k
            || cnt[2] - window[2] < k)
            ){
                --window[s[l++] - 'a'];
            }
            maxWindow = max(maxWindow, r - l + 1);
        }
        
        return n - maxWindow;
    }
};
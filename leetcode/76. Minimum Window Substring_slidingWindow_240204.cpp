class Solution {
    int tUCnt[26], tLCnt[26];
    int sUCnt[26], sLCnt[26];
    bool isWindow(){
        for(int i = 0; i<26; ++i){
            if(tUCnt[i] > sUCnt[i] || tLCnt[i] > sLCnt[i])
                return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        for(char c: t){
            if(c >= 'a') tLCnt[c -'a']++;
            else tUCnt[c-'A']++;
        }

        int l = 0, r = 1e9, n =s.size();
        for(int i = 0, j =0; i<n; ++i){
            while(j<n && !isWindow()){
                if(s[j] >= 'a') sLCnt[s[j] -'a']++;
                else sUCnt[s[j]-'A']++;
                j++;
            }
            if(r - l > j - i && isWindow()){
                l = i; r = j;
            }
            if(s[i] >= 'a') sLCnt[s[i] -'a']--;
            else sUCnt[s[i]-'A']--;
        }

        return r == 1e9?"":s.substr(l, r - l);
    }
};
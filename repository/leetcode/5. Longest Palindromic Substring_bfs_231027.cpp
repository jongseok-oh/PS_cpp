class Solution {
    struct Loc{int s,e;};
public:
    string longestPalindrome(string s) {
        int n = s.size();
        queue<Loc> q;
        for(int i = 0; i<n; ++i){
            q.push({i, i});
            if(i != n-1 && s[i] == s[i + 1])
                q.push({i, i + 1});
        }

        int retStart = 0;
        int maxLen = 1;
        while(q.size()){
            Loc t = q.front(); q.pop();

            int start = t.s, end = t.e;

            int len = end - start + 1;
            if(maxLen < len){
                retStart = start;
                maxLen = len;
            }

            if(start != 0 && end != n -1 && s[start-1] == s[end + 1])
                q.push({start-1, end + 1});
        }

        return s.substr(retStart, maxLen);
    }
};
class Solution {
    int lastIdx[26];
public:
    string removeDuplicateLetters(string s) {
        vector<char> stack;
        int visit = 0, n = s.size();

        for(int i = 0; i<n; ++i)
            lastIdx[s[i]-'a'] = i;

        for(int i =0; i<n; ++i){
            int tIdx = s[i]-'a';
            if(visit & (1<<tIdx)) continue;

            while(stack.size() && stack.back() > s[i] && i < lastIdx[stack.back()-'a']){
                visit &= ~(1<<(stack.back() - 'a'));
                stack.pop_back();
            }

            stack.push_back(s[i]);
            visit |= 1<<tIdx;
        }

        string ret ="";

        for(char& c: stack) ret.push_back(c);

        return ret;
    }
};
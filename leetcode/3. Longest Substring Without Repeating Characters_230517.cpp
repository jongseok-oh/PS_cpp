class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        if(!n) return 0;

        int left = 0, right = 1, ans = 1;
        unordered_map<char, int> m;
        m[s[0]] = 1;

        for(int left = 0; left<n; left++){
            while(right <=n && m[s[right - 1]] < 2){
                m[s[right]]++; right++;
            }
            ans = max(ans, right - left - 1);
            m[s[left]]--;
        }
        return ans;
    }
};
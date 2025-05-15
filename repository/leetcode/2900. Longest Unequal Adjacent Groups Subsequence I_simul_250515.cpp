class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = groups.size();
        vector<string> ret;

        for(int i = 0; i<n;){
            ret.push_back(words[i]);
            int j = i + 1;
            while(j < n && groups[j - 1] == groups[j]) ++j;
            i = j;
        }
        
        return ret;
    }
};
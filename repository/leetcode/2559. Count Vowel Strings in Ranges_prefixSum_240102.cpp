class Solution {
    bool isVowel(char c){
        return c == 'a' || c == 'e' ||c == 'i' ||c == 'o' ||c == 'u';
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefixSum(n + 1);
        for(int i = 0; i<n; ++i){
            string word = words[i];
            prefixSum[i + 1] = prefixSum[i] + (isVowel(word.front()) && isVowel(word.back()));
        }

        int m = queries.size();
        vector<int> ret(m);
        for(int i = 0; i<m; ++i){
            auto& q = queries[i];
            ret[i] = prefixSum[q[1] + 1] - prefixSum[q[0]];
        }

        return ret;
    }
};
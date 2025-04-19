class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> endIdx(26);
        for(int i = 0; i<n; ++i){
            endIdx[s[i] - 'a'] = i;
        }

        vector<int> ret;
        for(int i = 0; i<n;){
            int start = i;
            int end = endIdx[s[i]-'a'];
            while(i++ < end){
                end = max(end, endIdx[s[i]-'a']);
            }
            ret.push_back(end - start + 1);
        }

        return ret;
    }
};
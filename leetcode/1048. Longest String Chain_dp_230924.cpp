class Solution {
    int dp[1000];
    vector<int> wordLen[18];

    bool isChain(int idx1, int idx2, vector<string>& words){
        auto& small = words[idx1];
        auto& big = words[idx2];

        int diffCnt = 0;
        for(int j = 0, i = 0; j<big.size(); j++){
            if(small[i] != big[j]){
                if(++diffCnt > 1) return false;
                continue;
            }
            ++i;
        }

        return true;
    }

    int solve(int idx, vector<string>& words){
        int& ret = dp[idx];

        if(ret) return ret;

        ret = 1;

        for(int& nIdx : wordLen[words[idx].size() + 1])
            if(isChain(idx, nIdx, words))
                ret = max(ret, 1 + solve(nIdx, words));

        return ret;
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const auto& a,const auto& b){
            return a.size() < b.size();
        });
        for(int i = 0; i<words.size(); ++i)
            wordLen[words[i].size()].push_back(i);

        int ret = 1;

        for(int i = 0; i<words.size(); ++i)
            ret = max(ret, solve(i, words));
        
        return ret;
    }
};
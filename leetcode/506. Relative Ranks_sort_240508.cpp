class Solution {
    struct Score{int score, idx;};
    vector<string> medals = {"Gold Medal", "Silver Medal", "Bronze Medal"};
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<Score> vec(n);
        for(int i = 0; i<n; ++i) vec[i] = {score[i],i};

        sort(vec.begin(), vec.end(), [&](auto& s1, auto& s2){
            return s1.score > s2.score;
        });

        vector<string> ret(n);

        for(int i = 0; i<n; ++i){
            if(i < 3) ret[vec[i].idx] = medals[i];
            else ret[vec[i].idx] = to_string(i + 1);
        }

        return ret;
    }
};
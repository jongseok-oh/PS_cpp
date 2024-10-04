class Solution {
    using ll = long long;
public:
    long long dividePlayers(vector<int>& skill) {
        vector<int> cnt(1001);
        int sum = 0, n = skill.size();
        for(int s : skill){
            sum += s;
            ++cnt[s];
        }

        if(sum % (n/2) != 0) return -1;

        ll ret = 0, tar = sum / (n/2);
        for(int s : skill){
            if(cnt[s] == 0) continue;
            --cnt[s];
            int pair = tar - s;
            if(pair <= 0 || cnt[pair] == 0) return -1;
            --cnt[pair];

            ret += s * pair;
        }

        return ret;
    }
};
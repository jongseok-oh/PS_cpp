class Solution {
    bool visit[1<<26];
    struct BitCnt{int bit, cnt;};

    int solve(int idx, int tVisit, vector<BitCnt>& bits){
        if(idx == bits.size()) return 0;

        int ret = 0;
        for(int i = idx; i<bits.size(); ++i){
            if((tVisit & bits[i].bit) || visit[tVisit | bits[i].bit]) continue;
            visit[tVisit | bits[i].bit] = true;
            ret = max(ret, bits[i].cnt + solve(i + 1, tVisit | bits[i].bit, bits));
        }
        return ret;
    }
public:
    int maxLength(vector<string>& arr) {
        vector<BitCnt> bits;

        for(auto& str: arr){
            int bit = 0, cnt = 0;
            for(char c: str){
                int t = 1 <<(c-'a');
                if(t & bit) {cnt = 0; break;}
                else {bit |= t; ++cnt;}
            }
            if(cnt) bits.push_back({bit, cnt});
        }

        return solve(0, 0, bits);
    }
};
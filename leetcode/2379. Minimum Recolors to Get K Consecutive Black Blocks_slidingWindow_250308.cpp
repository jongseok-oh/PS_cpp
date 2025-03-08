class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int whiteCnt = 0;
        for(int i = 0; i<k-1; ++i){
            if(blocks[i] == 'W') ++whiteCnt;
        }

        int ret = 1e9;
        for(int i = k -1, n = blocks.size(); i<n; ++i){
            if(blocks[i] == 'W') ++whiteCnt;
            ret = min(ret, whiteCnt);
            if(blocks[i - (k-1)] == 'W') --whiteCnt;
        }

        return ret;
    }
};
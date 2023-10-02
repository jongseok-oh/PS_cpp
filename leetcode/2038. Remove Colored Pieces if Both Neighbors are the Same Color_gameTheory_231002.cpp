class Solution {
    int cnts[2];
public:
    bool winnerOfGame(string colors) {
        bool isB = colors[0] == 'B';
        int tCnt = 1;

        for(int i = 0; i<colors.size(); ++i){
            if(i == colors.size() - 1 || colors[i + 1] - 'A' != isB){
                if(tCnt >= 3) cnts[isB] += tCnt - 2;
                isB ^= 1;
                tCnt = 1;
            }else tCnt++;
        }

        return cnts[0] > cnts[1];
    }
};
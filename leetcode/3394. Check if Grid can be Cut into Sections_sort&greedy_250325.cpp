class Solution {
    const int mask = 0x80000000;
    bool isVaildCuts(vector<int>& dots){
        sort(dots.begin(), dots.end(), [&](int dot1, int dot2){
            int maskDot1 = dot1<0?dot1 ^ mask:dot1;
            int maskDot2 = dot2<0?dot2 ^ mask:dot2;
            return maskDot1 < maskDot2
            || (maskDot1 == maskDot2 && dot1 < dot2);
        });

        int sCnt = 0, lineCnt = 0;
        for(int dot : dots){
            if(dot >= 0) ++sCnt;
            else --sCnt;
            if(sCnt == 0) ++lineCnt;
        }

        return lineCnt >=3;
    }
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<int> xDots, yDots;
        for(auto& rectangle : rectangles){
            int sx = rectangle[0], sy = rectangle[1];
            int ex = rectangle[2], ey = rectangle[3];
            xDots.push_back(sx);
            xDots.push_back(ex | mask);
            yDots.push_back(sy);
            yDots.push_back(ey | mask);
        }
        return isVaildCuts(xDots) || isVaildCuts(yDots);
    }
};
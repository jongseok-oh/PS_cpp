class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        
        int ret = 0;

        int moveTime = 0, mMoveTime = 0, pMoveTime = 0, gMoveTime = 0;
        for(int i = 0; i<n; ++i){
            if(i) moveTime += travel[i-1];

            int mCnt = 0, pCnt = 0, gCnt = 0;
            for(char& c : garbage[i]){
                if(c == 'M') ++mCnt;
                else if( c == 'P') ++pCnt;
                else ++gCnt;
            }

            if(mCnt) ret += mCnt, mMoveTime = moveTime;
            if(pCnt) ret += pCnt, pMoveTime = moveTime;
            if(gCnt) ret += gCnt, gMoveTime = moveTime;
        }

        return ret + mMoveTime + pMoveTime + gMoveTime;
    }
};
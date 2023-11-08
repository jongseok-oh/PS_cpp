class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int xlen = abs(sx - fx);
        int ylen = abs(sy - fy);

        int shortestDist = max(xlen, ylen);

        if(shortestDist == 0 && t == 1) return false;

        return shortestDist <=t;
    }
};
class Solution {
public:
    int findClosest(int x, int y, int z) {
        int xDiff = abs(z - x), yDiff = abs(z - y);
        return xDiff > yDiff?2:(xDiff < yDiff?1:0);
    }
};
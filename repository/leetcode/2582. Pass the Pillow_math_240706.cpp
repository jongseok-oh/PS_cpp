class Solution {
public:
    int passThePillow(int n, int time) {
        int chunk = time / (n-1), remain = time % (n-1);
        return chunk&1?n - remain:remain + 1;
    }
};
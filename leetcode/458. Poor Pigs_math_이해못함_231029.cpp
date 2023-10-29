class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        return ceil(log2(buckets)/log2(minutesToTest / minutesToDie +1));
    }
};
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int emptyBottles = 0, ret = 0;
        while(numBottles){
            ret += numBottles;
            emptyBottles += numBottles;
            numBottles = emptyBottles/numExchange;
            emptyBottles %= numExchange;
        }
        return ret;
    }
};
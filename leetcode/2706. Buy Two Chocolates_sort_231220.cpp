class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        int one = prices[0] ,two = prices[1];
        return one+two>money?money:money-one-two;
    }
};
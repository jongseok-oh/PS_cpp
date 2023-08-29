class Solution {
public:
    int bestClosingTime(string customers) {

        int sum = 0;
        for(int i = 0; i<customers.size(); i++){
            if(customers[i] == 'Y') ++sum;
        }
        int ans = 0, minPay = sum;

        for(int i = 1; i<=customers.size(); i++){
            if(customers[i - 1] == 'Y') --sum;
            else ++sum;

            if(sum < minPay) {
                ans = i;
                minPay = sum;
            }
        }

        return ans;
    }
};
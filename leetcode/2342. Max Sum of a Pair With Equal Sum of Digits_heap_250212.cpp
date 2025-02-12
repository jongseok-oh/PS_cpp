class Solution {
    int sumOfDigits(int num){
        int ret = 0;
        while(num){
            ret += num % 10;
            num /= 10;
        }
        return ret;
    }
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, priority_queue<int, vector<int>, greater<>>> map;

        for(int num : nums){
            int sum = sumOfDigits(num);
            map[sum].push(num);

            while(map[sum].size() > 2) map[sum].pop();
        }

        int ret = -1;
        for(auto& [k, pq] : map){
            if(pq.size() == 2){
                int sum = pq.top(); pq.pop();
                sum += pq.top();
                ret = max(ret, sum);
            }
        }

        return ret;
    }
};
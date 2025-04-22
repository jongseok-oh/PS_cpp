class Solution {
    int sumDigit(int num){
        int sum = 0;
        while(num){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
public:
    int countLargestGroup(int n) {
        vector<int> cnt(37);
        for(int i = 1; i<=n; ++i) ++cnt[sumDigit(i)];
        int _max = *max_element(cnt.begin(), cnt.end());

        int ans = 0;
        for(int c : cnt){
            ans += c == _max;
        }
        return ans;
    }
};
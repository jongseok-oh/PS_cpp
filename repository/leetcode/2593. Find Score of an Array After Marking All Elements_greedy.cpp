class Solution {
    using ll = long long;
public:
    ll findScore(vector<int> &nums) {
        ll ans = 0;
        // 개쩐다. 이런건 어떻게 생각함? ㅋ
        // 문제에선 항상 최소 값을 찾고 마킹한다 했지만
        // 결국 선택되는 수는 항상 같음을 이용
        for (int i = 0, n = nums.size(); i < n; i += 2) {
            int i0 = i;
            // 내리막을 찾는다.
            while (i + 1 < n && nums[i] > nums[i + 1])
                ++i;
            // 내리막을 올라가면서 양 옆의 수를 마킹하며 스킵
            for (int j = i; j >= i0; j -= 2)
                ans += nums[j];
        }
        return ans;
    }
};
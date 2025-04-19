class Solution {
    using ll = long long;
    ll calcChildren(int candySize, vector<int>& candies){
        ll children = 0;
        for(int candy : candies){
            children += candy/candySize;
        }
        return children;
    }
public:
    int maximumCandies(vector<int>& candies, ll k) {
        int maxSize = *max_element(candies.begin(), candies.end());
        int low = 0, high = maxSize + 1;
        while(low + 1 < high){
            int mid = (low + high)>>1;
            if(calcChildren(mid, candies) >= k){
                low = mid;
            }else high = mid;
        }
        return low;
    }
};
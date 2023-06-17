class Solution {

    int dp[2000][2000][2];

    int uper_bound(int tar, vector<int>& arr2){
        
        int low = -1, high = arr2.size();

        while(low + 1 < high){
            int mid = (low + high)>>1;
            
            if(arr2[mid] > tar) high = mid;
            else low = mid;
        }

        return high;
    }

    int solve(int i, int j, int updated,vector<int>& arr1, vector<int>& arr2){
        if(i == arr1.size()) return 0;
        
        int& ret = dp[i][j][updated];

        if(ret != -1) return ret;

        ret = 1e9;

        int prev = (i == 0?-1:(updated == 0?arr1[i - 1]:arr2[j]));
        
        if(arr1[i] > prev) ret = solve(i + 1, j, 0, arr1, arr2);

        int idx = uper_bound(prev, arr2);

        if(idx != arr2.size())
            ret = min(ret, solve(i + 1, idx, 1, arr1, arr2) + 1);
        
        return ret;
    }
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());

        memset(dp, -1, sizeof(dp));

        int ans = solve(0,0,1 ,arr1,arr2);
        return (ans == 1e9?-1:ans);
    }
};
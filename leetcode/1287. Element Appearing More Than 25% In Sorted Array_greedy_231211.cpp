class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        double tar = n/4;

        int prev = arr[0], cnt = 1;
        for(int i = 1; i<n; ++i){
            if(prev == arr[i]) ++cnt;
            else cnt = 1, prev = arr[i];

            if(cnt > tar) return prev;
        }

        return arr[0];
    }
};
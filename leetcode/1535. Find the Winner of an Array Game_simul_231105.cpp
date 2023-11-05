class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int tMax = arr[0], tWin = 0;

        for(int i = 1; i<arr.size(); ++i){
            int tNum = arr[i];

            if(tNum > tMax){
                tMax = tNum;
                tWin = 1;
            }else ++tWin;

            if(tWin == k) return tMax;
        }

        return tMax;
    }
};
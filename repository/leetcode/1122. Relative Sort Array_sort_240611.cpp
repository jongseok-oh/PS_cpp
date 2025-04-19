class Solution {
    int idx[1001];
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        memset(idx, 0x7f, sizeof idx);
        for(int i = 0; i<arr2.size(); ++i)
            idx[arr2[i]] = i;
        
        sort(arr1.begin(), arr1.end(), [&](int a, int b){
            return idx[a] < idx[b] || (idx[a] == idx[b] && a < b);
        });
        return arr1;
    }
};
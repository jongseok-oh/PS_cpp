class Solution {
    int calcPrfixCnt(string& s1, string& s2){
        int length = min(s1.size(), s2.size());

        int cnt = 0;
        for(int i = 0; i<length; ++i){
            if(s1[i] != s2[i]) break;
            ++cnt;
        }

        return cnt;
    }
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size();
        if(n > m) return longestCommonPrefix(arr2, arr1);

        vector<string> str1(n), str2(m);

        for(int i = 0; i<n; ++i) str1[i] = to_string(arr1[i]);
        for(int i = 0; i<m; ++i) str2[i] = to_string(arr2[i]);

        sort(str2.begin(), str2.end());

        int ret = 0;
        for(string& str : str1){
            auto it = lower_bound(str2.begin(), str2.end(), str);
            if(it != str2.begin()){
                ret = max(ret, calcPrfixCnt(str, *(it -1)));
            }
            if(it != str2.end()){
                ret = max(ret, calcPrfixCnt(str, *it));
            }
        }

        return ret;
    }
};
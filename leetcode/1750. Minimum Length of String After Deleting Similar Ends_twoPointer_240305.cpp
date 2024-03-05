class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int left = 0, right = n -1;

        while(left <= right){
            if(left == right || s[left] != s[right]) return right - left + 1;
            char target = s[left];
            while(left <= right && s[left] == target) ++left;
            while(right > left && s[right] == target) --right;
        }
        return 0;
    }
};
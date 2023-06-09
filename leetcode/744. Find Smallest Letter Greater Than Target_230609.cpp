class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int low = -1, high = letters.size();

        while(low + 1 <high){
            int mid = (low + high) >> 1;

            if(letters[mid] > target) high = mid;
            else low = mid;
        }

        return high == letters.size()?letters[0]:letters[high];
    }
};
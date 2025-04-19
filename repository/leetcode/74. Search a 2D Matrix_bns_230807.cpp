class Solution {
    
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();

        int low = -1, high = n*m;

        while(low + 1 < high){
            int mid = (low + high) >>1;

            int row = mid / m, col = mid % m;

            if(matrix[row][col] == target) return true;

            if(matrix[row][col] > target) high = mid;
            else low = mid;
        }

        return false;
    }
};
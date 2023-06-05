class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        sort(coordinates.begin(), coordinates.end(), [](const vector<int>& a,const vector<int>& b){
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });

        double inc = ((double)(coordinates[1][1] - coordinates[0][1]))/(coordinates[1][0] - coordinates[0][0]);

        for(int i = 1; i<coordinates.size()-1; i++){
            if(inc != ((double)(coordinates[i+1][1] - coordinates[i][1]))/(coordinates[i+1][0] - coordinates[i][0]))
                return false;
        }

        return true;
    }
};
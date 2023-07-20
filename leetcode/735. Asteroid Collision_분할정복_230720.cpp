class Solution {
    vector<int> solve(vector<int> left, vector<int> right){
        int n = left.size(), m = right.size();
        
        if(n >= 2) left = solve(vector<int>(left.begin(), left.begin() + n/2),
        vector<int>(left.begin() + n/2, left.end()));

        if(m >= 2) right = solve(vector<int>(right.begin(), right.begin() + m/2),
        vector<int>(right.begin() + m/2, right.end()));

        int leftIdx = left.size() -1, rightIdx = 0;

        while(leftIdx >= 0 && rightIdx < right.size()){
            if(left[leftIdx] > 0 && right[rightIdx] < 0){
                int _left = abs(left[leftIdx]), _right = abs(right[rightIdx]);
                if(_left > _right) rightIdx++;
                else if(_left < _right) leftIdx--;
                else rightIdx++, leftIdx--;
            }else break;
        }

        vector<int> ret;

        for(int i = 0; i<=leftIdx; i++) ret.push_back(left[i]);
        for(int i = rightIdx; i<right.size(); i++) ret.push_back(right[i]);

        return ret;
    }
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int _size = asteroids.size();
        return solve(vector<int>(asteroids.begin(), asteroids.begin() + _size/2),
                    vector<int>(asteroids.begin() + _size/2, asteroids.end())
        );
    }
};
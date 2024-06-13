class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        
        int ret =0;
        for(int i = 0, n = seats.size(); i<n; ++i)
            ret += abs(seats[i] - students[i]);
        return ret;
    }
};
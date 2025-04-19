const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int result = 0;
        int low = 0, high = people.size()-1;
        while(low <= high){
            int remain = limit - people[high--];

            if(low <= high && remain >= people[low])
                ++low;
            
            ++result;
        }
        return result;
    }
};
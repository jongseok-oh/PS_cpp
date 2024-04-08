class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> prefer;
        for(auto it = students.rbegin(); it != students.rend(); ++it)
            prefer.push(*it);
        
        int noEatCnt = 0, sandwichIdx = 0;
        while(noEatCnt != prefer.size()){
            if(sandwiches[sandwichIdx] == prefer.front()){
                noEatCnt = 0;
                prefer.pop();
                ++sandwichIdx;
            }else{
                prefer.push(prefer.front());
                prefer.pop();
                ++noEatCnt;
            }
        }

        return noEatCnt;
    }
};
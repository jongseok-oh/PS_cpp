class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> charge(2);
        for(int bill : bills){
            if(bill == 5) ++charge[0];
            else if(bill == 10){
                if(!charge[0]) return false;
                --charge[0]; ++charge[1];
            }else if(bill == 20){
                if(charge[1] && charge[0]){
                    --charge[1]; --charge[0];
                }else{
                    if(charge[0] <3) return false;
                    charge[0] -= 3;
                }
            }
        }
        return true;
    }
};
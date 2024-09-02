class Solution {
    using ll = long long;
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        ll sum = 0;
        for(int ch : chalk) {
            sum += ch;
        }
        
        k %= sum;
        for(int i = 0; i<chalk.size(); ++i){
            int ch = chalk[i]; 
            if(k < ch){
                return i;
            }
            k -= ch;
        }
        return -1;
    }
};
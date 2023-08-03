class Solution {
    string temp;

    void comb(int idx, string& digits, vector<string>& ret, vector<vector<char>>& converter){
        if(idx == digits.size()){
            ret.push_back(temp); return;
        }

        int num = digits[idx] - '0';
        for(int i = 0; i<converter[num].size(); i++){
            temp[idx] = converter[num][i];
            comb(idx+1, digits, ret, converter);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;

        if(!digits.size()) return ret;

        vector<vector<char>> converter(10);

        converter[2] = {'a','b','c'};
        converter[3] = {'d','e','f'};
        converter[4] = {'g','h','i'};
        converter[5] = {'j','k','l'};
        converter[6] = {'m','n','o'};
        converter[7] = {'p','q','r','s'};
        converter[8] = {'t','u','v'};
        converter[9] = {'w','x','y','z'};


        temp = digits;
        comb(0, digits, ret, converter);
        return ret;
    }
};
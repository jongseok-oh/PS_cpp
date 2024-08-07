class Solution {
    vector<string> less_than_twenty = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

    vector<string> ten_places = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    vector<string> three_places = {"", " Thousand", " Million", " Billion"};

    string convertTwo(int num){
        if(num < 20) return less_than_twenty[num];
        return ten_places[num/10] + (num % 10 == 0?"":" ") + less_than_twenty[num%10];
    }
    string convertThree(int num){
        if(num >= 100) {
            string three = less_than_twenty[num/100] + " Hundred";
            string two = convertTwo(num % 100);
            return three + (two.size()?" ":"") + two;
        }
        return convertTwo(num);
    }
public:
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        vector<string> tokens;
        while(num){
            tokens.push_back(convertThree(num%1000));
            num /= 1000;
        }
        string ret;
        for(int i = tokens.size() -1; i>=0; --i){
            string token = tokens[i];
            if(token.size()) {
                if(ret.size()) ret += " ";
                ret += token + three_places[i];
            }
        }
        return ret;
    }
};
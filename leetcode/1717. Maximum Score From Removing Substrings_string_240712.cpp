class Solution {
public:
    int removePairs(string &s, string target) {
        int write_ind = 0, count = 0;
        for (char c : s) {
            s[write_ind] = c;
            write_ind++;
            if (write_ind >= 2 && s[write_ind - 1] == target[1] && s[write_ind - 2] == target[0]) {
                count++;
                write_ind -= 2;
            }
        }
        s.resize(write_ind);
        return count;
    }

    int maximumGain(string s, int x, int y) {
        int res = 0;
        string top, bot;
        int top_score, bot_score;

        if (y > x) {
            top = "ba";
            top_score = y;
            bot = "ab";
            bot_score = x;
        } else {
            top = "ab";
            top_score = x;
            bot = "ba";
            bot_score = y;
        }

        res += removePairs(s, top) * top_score;
        res += removePairs(s, bot) * bot_score;
        return res;
    }
};
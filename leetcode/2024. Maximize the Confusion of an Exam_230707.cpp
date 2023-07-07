class Solution {
    int converChar(char c){
        if(c == 'T') return 0;
        else return 1;
    }
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int maxFreq = 0;
        int i = 0;
        int charCount[2] = {0,};

        for (int j = 0; j < answerKey.length(); j++) {
            int currentChar = converChar(answerKey[j]);
            charCount[currentChar]++;
            maxFreq = max(maxFreq, charCount[currentChar]);

            if (j - i + 1 > maxFreq + k) {
                charCount[converChar(answerKey[i])]--;
                i++;
            }
        }

        return answerKey.length() - i;
    }
};
class Solution {
    bool visit[10000];
    const int digits[4] = {1,10, 100, 1000};
    int increase(int num, int digit){
        int upperDigit = digit * 10;
        int front = num / upperDigit * upperDigit;
        int back = (num % upperDigit + digit) % upperDigit;
        return front + back;
    }
    int decrease(int num, int digit){
        int upperDigit = digit * 10;
        int front = num / upperDigit * upperDigit;
        int back = (num % upperDigit + 9 * digit) % upperDigit;
        return front + back;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        for(string& end: deadends) visit[stoi(end)] = true;

        if(visit[0]) return -1;
        
        int tar = stoi(target);
        
        queue<int> q;
        q.push(0);
        visit[0] = true;

        int result = 0;
        while(q.size()){
            int qsize = q.size();
            while(qsize--){
                int num = q.front(); q.pop();
                if(num == tar) return result;

                for(int i = 0; i<4; ++i){
                    int digit = digits[i];
                    
                    int incNum = increase(num, digit);
                    int decNum = decrease(num, digit);

                    if(!visit[incNum]){
                        visit[incNum] = true;
                        q.push(incNum);
                    }
                    if(!visit[decNum]){
                        visit[decNum] = true;
                        q.push(decNum);
                    }
                }
            }
            ++result;
        }
        return -1;
    }
};
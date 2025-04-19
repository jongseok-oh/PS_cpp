#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    int i = 0, len = s.size();
    
    while(true){
        char t = s[i];
        int same = 1, dif = 0;
        i++;
        while(i<len && same != dif){
            if(s[i] == t) same++;
            else dif++;
            i++;
        }
        answer++;
        if(i == len) break;
    }
    
    return answer;
}
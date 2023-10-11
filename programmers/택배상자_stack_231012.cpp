#include <string>
#include <vector>

using namespace std;

int solution(vector<int> order) {
    int answer = 0, n = order.size();
    
    int tNum = 1;
    vector<int> st;
    for(int& ord: order){
        if(ord == tNum){
            answer++; tNum++;
        }else if(ord > tNum){
            while(ord != tNum)
                st.push_back(tNum++);
            answer++; tNum++;
        }else{
            if(!st.size() || st.back() != ord) break;
            else answer++, st.pop_back();
        }
    }
    
    return answer;
}
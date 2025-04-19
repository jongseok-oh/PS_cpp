#include <string>
#include <vector>

using namespace std;

string solution(vector<string> arr) {
    string ret = "";
    
    for(auto& str: arr) ret += str;
    
    return ret;
}
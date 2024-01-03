class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> cnts;
        
        for(auto& s: bank){
            int cnt = 0;
            for(char& c: s)
                if(c == '1') ++cnt;
            if(cnt) cnts.push_back(cnt);
        }
        int ret = 0, n = cnts.size();
        for(int i = 0; i<n; ++i){
            if(i != n-1) ret += cnts[i] * cnts[i+1];
        }
        return ret;
    }
};
class Solution {
    int cCnt[26];
public:
    string reorganizeString(string s) {
        for(auto& c: s) cCnt[c - 'a']++;

        priority_queue<pair<int, char>> q;

        for(int i = 0; i<26; i++)
            if(cCnt[i]) q.push({cCnt[i], i + 'a'});

        string ret = "";
        while(q.size() >= 2){
            auto [cnt1, c1] = q.top(); q.pop();
            auto [cnt2, c2] = q.top(); q.pop();

            ret.push_back(c1);
            ret.push_back(c2);

            if(--cnt1) q.push({cnt1, c1});
            if(--cnt2) q.push({cnt2, c2});
        }

        if(q.size()){
            auto [cnt, c] = q.top();

            if(cnt > 1) return "";

            ret.push_back(c);
        }

        return ret;
    }
};
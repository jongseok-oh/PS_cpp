class Solution {
    int cnt[26];


public:
    int minDeletions(string s) {
        for(char& c: s) cnt[c - 'a']++;

        unordered_map<int, int> ccnt;

        for(int i = 0; i<26; i++){
            if(cnt[i]) ccnt[cnt[i]]++;
        }

        int ret = 0;

        while(true){
            bool end = true;
            for(auto it = ccnt.begin(); it != ccnt.end(); it++){
                if(it -> second > 1){
                    int val = it -> second -1, key = it->first - 1;
                    ret += val;
                    if(key) ccnt[key] += val;
                    ccnt[key + 1] = 1;
                    end = false;
                    break;
                }
            }

            if(end) break;
        }

        return ret;
    }
};
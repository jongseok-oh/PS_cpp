class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> cnt(10);
        for(int d : digits) ++cnt[d];

        vector<int> ret;
        for(int i = 1; i<10; ++i){
            if(cnt[i] == 0) continue;
            int num = i * 100;
            --cnt[i];
            for(int j = 0; j<10; ++j){
                if(cnt[j] == 0) continue;
                num += j * 10;
                --cnt[j];
                for(int k = 0; k<10; k += 2){
                    if(cnt[k]){
                        if(ret.empty() || ret.back() != num + k){
                            ret.push_back(num + k);
                        }
                    }
                }
                ++cnt[j];
                num -= j * 10;
            }
            ++cnt[i];
        }

        return ret;
    }
};
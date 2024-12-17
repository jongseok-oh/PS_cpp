class Solution {
    int bulk = 1, flag = 2;
    int findNextPivot(int pivot, vector<int>& cnt){
        for(int i = pivot -1; i>= 0; --i){
            if(cnt[i]) return i;
        }
        return -1;
    }
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> cnt(26);
        for(char c : s) ++cnt[c -'a'];

        int pivot1 = -1, pivot2 = -1;
        for(int i = 25; i>=0; --i){
            if(cnt[i]){
                if(pivot1 == -1) pivot1 = i;
                else if(pivot2 == -1){
                    pivot2 = i; break;
                }
            }
        }

        int state = bulk;
        string ret;
        while(true){
            if(state == bulk){
                if(pivot1 == -1) break;
                if(cnt[pivot1] > repeatLimit){
                    ret += string(repeatLimit, pivot1 + 'a');
                    cnt[pivot1] -= repeatLimit;
                    state = flag;
                }else{
                    int limit = cnt[pivot1];
                    cnt[pivot1] = 0;
                    ret += string(limit, pivot1 + 'a');
                    int nextPivot2 = findNextPivot(pivot2, cnt);
                    pivot1 = pivot2;
                    pivot2 = nextPivot2;
                }
            }else{
                if(pivot2 == -1) break;
                ret.push_back(pivot2 + 'a');
                if(--cnt[pivot2] == 0){
                    pivot2 = findNextPivot(pivot2, cnt);
                }
                state = bulk;
            }
        }

        return ret;
    }
};
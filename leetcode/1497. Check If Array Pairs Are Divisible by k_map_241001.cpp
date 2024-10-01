class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> map(k);
        
        for(int num : arr){
            num = ((num % k) + k) % k;
            ++map[num];
        }
        
        for(int num = 0; num<k; ++num){
            int cnt = map[num];
            if(cnt == 0) continue;
            int other = (k - num) % k;
            if(map[other] == 0) return false;
            if(num == other){
                if(cnt % 2 != 0) return false;
            }else{
                if(cnt != map[other]) return false;
            }
        }

        return true;
    }
};
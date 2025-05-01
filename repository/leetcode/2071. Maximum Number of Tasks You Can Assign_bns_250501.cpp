class Solution {
    bool check(int mid, vector<int>& tasks, vector<int>& workers, int pills, int strength){
        int n = tasks.size(), m = workers.size();

        deque<int> dq;
        for(int i = mid - 1, j = 0; i>=0; --i){
            while(j < min(n, m) && tasks[i] <= strength + workers[j]){
                dq.push_front(workers[j++]);
            }
            if(dq.empty()) return false;

            if(dq.back() >= tasks[i]){
                dq.pop_back();
            }else{
                if(pills){
                    --pills;
                    dq.pop_front();
                }else return false;
            }
        }

        return true;
    }
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end(), greater<>());

        int n = tasks.size(), m = workers.size();
        int low = 0, high = min(n, m) + 1;

        while(low + 1< high){
            int mid = (low + high)>>1;
            if(check(mid, tasks, workers, pills, strength)){
                low = mid;
            }else high = mid;
        }

        return low;
    }
};
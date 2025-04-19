class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0, ticketIdx = 0, n = tickets.size();
        while(tickets[k]){
            if(tickets[ticketIdx] > 0){
                --tickets[ticketIdx]; ++time;
            }
            ticketIdx = (ticketIdx + 1)%n;
        }
        return time;
    }
};
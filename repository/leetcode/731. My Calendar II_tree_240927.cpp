class MyCalendarTwo {
    using booked = pair<int, int>;
    map<int, int> calendar;
public:
    MyCalendarTwo() {}
    bool book(int start, int end) {
        ++calendar[start];
        --calendar[end];

        int prefixSum = 0;
        for(auto &[num, cnt] : calendar){
            prefixSum += cnt;
            if(prefixSum > 2){
                if(--calendar[start] == 0) calendar.erase(start);
                if(++calendar[end] == 0) calendar.erase(end);
                return false;
            }
        }
        
        return true;
    }
};
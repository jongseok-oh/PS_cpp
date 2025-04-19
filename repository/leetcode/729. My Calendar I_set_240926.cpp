class MyCalendar {
    using booked = pair<int,int>;
    set<booked> calendar;
public:
    MyCalendar() {}
    
    bool book(int start, int end) {
        auto it = calendar.upper_bound({start, 1e9});
        if(it == calendar.end() || it->second >= end){
            calendar.insert({end, start});
            return true;
        }
        return false;
    }
};
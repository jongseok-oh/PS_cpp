class UndergroundSystem {
    struct CheckIn{
        string station;
        int time;
    };
    unordered_map<int, CheckIn> checkIns;

    struct Pair{int timeSum, cnt;};
    unordered_map<string, unordered_map<string, Pair>> av;
public:
    UndergroundSystem() {

    }
    
    void checkIn(int id, string stationName, int t) {
        checkIns[id].station = stationName;
        checkIns[id].time = t;
    }
    
    void checkOut(int id, string stationName, int t) {
        string inStation = checkIns[id].station;
        int inTime = checkIns[id].time;

        Pair& pair = av[inStation][stationName];
        pair.timeSum += t - inTime;
        pair.cnt++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        Pair& pair = av[startStation][endStation];

        return (double)pair.timeSum / pair.cnt;
    }
};
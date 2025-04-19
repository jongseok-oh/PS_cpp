class ParkingSystem {
    int park[3];
public:
    ParkingSystem(int big, int medium, int small) {
        park[0] = big; park[1] = medium; park[2] = small;
    }
    
    bool addCar(int carType) {
        carType--;
        if(park[carType]){
            park[carType]--;
            return true;
        }
        return false;
    }
};
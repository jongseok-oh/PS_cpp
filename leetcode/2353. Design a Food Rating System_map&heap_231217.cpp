class FoodRatings {
    struct fr{
        string name;
        int rating;
        bool operator < (const auto& other)const{
            return rating < other.rating || (rating == other.rating && name > other.name);
        }
    };
    unordered_map<string, string> fc;
    unordered_map<string, int> tRating;
    unordered_map<string, priority_queue<fr>> cr;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0; i<n; ++i){
            fc[foods[i]] = cuisines[i];
            tRating[foods[i]] = ratings[i];
            cr[cuisines[i]].push({foods[i] , ratings[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        tRating[food] = newRating;
        cr[fc[food]].push({food, newRating});
    }
    
    string highestRated(string cuisine) {
        while(true){
            fr t = cr[cuisine].top();
            if(t.rating != tRating[t.name]) cr[cuisine].pop();
            else return t.name;
        }
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
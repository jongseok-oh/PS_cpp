class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> candies(n,1);

        for(int i = 1; i<n; ++i){
            if(ratings[i-1] <ratings[i])
                candies[i] = candies[i-1]+1;
        }
        
        int ret = 0;
        for(int i = n-2; i>=0; --i){
            ret += candies[i+1];

            if(ratings[i+1] <ratings[i] && candies[i+1]>=candies[i])
                candies[i] = candies[i+1]+1;
        }

        return ret + candies[0];
    }
};
class Solution {
    using ll = long long;
    string optical(string n){
        string opt = n;
        for(int i = 0, len = opt.size(); i<len/2; ++i){
            opt[len-i-1] = opt[i];
        }
        return opt;
    }
    vector<string> getCandies(string n){
        string opt = optical(n);
        vector<string> candies;
        candies.emplace_back(opt);
        // same length
        for(int len = opt.size(), i = len/2; i<len; ++i){
            string ret = opt;
            if(ret[i] != '0'){
                --ret[i];
                if(i != len - i -1){
                    --ret[len - i -1];
                }
                candies.emplace_back(ret);
            }
            ret = opt;
            if(ret[i] == '0' && i<len-1 && ret[i + 1] != '0'){
                ret[i] = '9';
                ret[len - i -1] = '9';
                --ret[i+1];
                --ret[len - i -2];
                candies.emplace_back(ret);
            }
            ret = opt;
            if(ret[i] != '9'){
                ++ret[i];
                if(i != len - i -1){
                    ++ret[len - i -1];
                }
                candies.emplace_back(ret);
            }
            ret = opt;
            if(ret[i] == '9' && i<len-1 && ret[i + 1] != '9'){
                ret[i] = '0';
                ret[len - i -1] = '0';
                
                ++ret[i+1];
                ++ret[len - i -2];
                candies.emplace_back(ret);
            }
        }
        // smaller length
        if(opt.size() != 1){
            candies.emplace_back(string(opt.size()-1, '9'));
        }
        // bigger length;
        string upper(opt.size() + 1, '0');
        upper[0] = '1'; upper[upper.size()-1] = '1';
        candies.emplace_back(upper);

        return candies;
    }
public:
    string nearestPalindromic(string n) {
        vector<string> candies = getCandies(n);
        
        ll diff = 1e18, numN = stol(n), ret = 1e18;
        for(string& candi : candies){
            ll numCandi = stol(candi);
            if(numCandi == numN) continue;

            ll tdiff = abs(numCandi - numN);
            if(tdiff < diff){
                diff = tdiff;
                ret = numCandi;
            }else if(tdiff == diff && ret > numCandi){
                ret = numCandi;
            }
        }
        return to_string(ret);
    }
};
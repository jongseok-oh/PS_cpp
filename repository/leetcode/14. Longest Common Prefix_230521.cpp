class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        sort(strs.begin(), strs.end(), [](string a, string b) -> bool{
            return a.size() < b.size();
        });

        int len = strs[0].size();
        
        while(len--){
            string tar = strs[0].substr(0,len+1);

            bool allMatch = true;

            for(int i = 1; i<strs.size(); i++){
                if(tar != strs[i].substr(0,len+1)){
                    allMatch = false; break;
                }
            }
            if (allMatch) return tar;
        }

        return "";
    }
};
class Solution {
    int binaryToNum(string& binary){
        int n = binary.size();
        int num = 0;
        for(int i = 0; i<n; ++i){
            if(binary[i] == '1'){
                num |= 1<<(n-i-1);
            }
        }
        return num;
    }
    string numToBinary(int num, int len){
        string binary(len, '0');
        for(int i = 0; i<len && num; ++i, num >>= 1){
            binary[len-i-1] += num&1;
        }
        return binary;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> set;
        for(string& binary : nums){
            set.insert(binaryToNum(binary));
        }
        int len = nums.size();
        for(int i = 0, n = 1<<len; i<n; ++i){
            if(!set.count(i)) {
                return numToBinary(i, len);
            }
        }
        return "";
    }
};
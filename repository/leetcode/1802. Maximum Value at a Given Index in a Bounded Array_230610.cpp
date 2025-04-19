class Solution {

    long long calcSum(int n, int index, int tar){
        
        long long leftSum = 0;
        if(tar - 1 > index){
            leftSum = (long long)(tar - index + tar -1) * index /2;
        }else{
            leftSum = (long long)tar * (tar - 1)/2 + index - tar + 1;
        }

        long long rightSum = 0;
        int len = n - (index + 1);
        if(tar - 1 > len){
            rightSum = (long long)(tar - len + tar - 1) * len / 2;
        }else{
            rightSum = (long long)tar * (tar - 1)/2 + len - (tar - 1);
        }
        
        //cout<<"calc : "<<leftSum<<" "<<rightSum<<"\n";
        return leftSum + rightSum + tar;
    }

public:
    int maxValue(int n, int index, int maxSum) {
        
        int low = 1, high = 1e9 + 1;
        while(low + 1 < high){
            int mid = (low + high) >>1;
            
            long long tsum = calcSum(n,index, mid);

            //cout<<low<<" "<<high<<" "<<tsum<<"\n";
            if(tsum > maxSum) high = mid;
            else low = mid;
        }

        return low;
    }
};
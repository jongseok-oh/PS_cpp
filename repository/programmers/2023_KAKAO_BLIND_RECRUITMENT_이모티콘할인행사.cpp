#include <string>
#include <vector>

using namespace std;

int n,m, emoticonSale[7];

int sales[] = {10,20,30,40};

int max_service = 0, max_sale = 0;

void calc(vector<vector<int>>& users, vector<int>& emoticons){
    int tservice = 0, tsale = 0;
    
    for(auto& user: users){
        int usale = user[0], umoney = user[1], tsum = 0;
        for(int i = 0; i<m; i++){
            if(emoticonSale[i]>=usale)
                tsum += emoticons[i] * (100 - emoticonSale[i])/100;
        }
        if(tsum >= umoney) tservice++;
        else tsale += tsum;
    }
    if(tservice > max_service){
        max_service = tservice;
        max_sale = tsale;
    }else if(tservice == max_service){
        max_sale = max_sale>tsale?max_sale:tsale;
    }
}

void makeSale(int idx, vector<vector<int>>& users, vector<int>& emoticons) {
    if(idx == m){
        calc(users,emoticons); return;
    }
    for(int i = 0; i<4; i++){
        for(int j = idx; j<m; j++)
        {
            emoticonSale[j] = sales[i];
            makeSale(j+1,users,emoticons);
        }
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    n = users.size(); m = emoticons.size();
    vector<int> answer;
    makeSale(0,users,emoticons);
    answer.push_back(max_service);
    answer.push_back(max_sale);
    return answer;
}
class Solution {
public:
    unordered_map<string,int> dp;
    int answer(vector<int>& price, vector<vector<int>>& special, vector<int> needs,int i){
        if(i>=special.size()){
            int k = 0;
            for (int j=0;j<needs.size();++j) k += needs[j]*price[j];
            return k;
        };

        string key = to_string(i);
        for (int j : needs) key += to_string(j) + ",";

        if(dp[key]) return dp[key];

        int take = 1e8,noTake = 1e8,temp=0;
        bool flag=true;
        vector<int> newNeeds;

        for(int j=0;j<needs.size();++j){
            if(special[i][j]>needs[j]){
                flag=false;
                break;
            }
            temp += special[i][j]*price[j];
            newNeeds.push_back(needs[j]-special[i][j]);
        }

        if(flag && temp>special[i].back()){
            take = special[i].back() + answer(price,special,newNeeds,i);
        }
        noTake = answer(price,special,needs,i+1);
        return dp[key]=min(take,noTake);
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return answer(price,special,needs,0);
    }
};
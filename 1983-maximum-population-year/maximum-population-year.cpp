class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int,int>mpp;
        for(int i=0;i<logs.size();i++){
            for(int j=logs[i][0];j<logs[i][1];j++)mpp[j]++;
        }
        int year=0;int pop=0;
        for(auto it:mpp){
            if(it.second>pop){year=it.first;
            pop=it.second;
            }
        }
        return year;
    }
};
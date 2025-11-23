class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& g) {
        int xorr=0;
        int a=0,b=0;
    unordered_map<int,int>mpp;
    for(int i=0;i<g.size();i++){
        for(int j=0;j<g[0].size();j++){
            mpp[g[i][j]]++;

        }
    }
    int i=1;
    for(auto it:mpp){
        if(it.second==2){a=it.first;xorr^=i,i++;}
        xorr^=i;i++;
        xorr^=it.first;
        
    }
    return {a,xorr};
    }
};
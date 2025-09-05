class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int>mpp;
        for(auto it:arr)mpp[it]++;
        for(auto it:mpp){
            if(it.second>(int)(arr.size()/4))return it.first;
        }
        return 0;
        
    }
};
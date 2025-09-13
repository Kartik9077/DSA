class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int>mpp;
        for(auto it:s)mpp[it]++;
        int max_v=0,max_c=0;
        for(auto it:mpp){
            if(it.first=='a'||it.first=='e'||it.first=='i'||it.first=='o'||it.first=='u'){
                if(max_v<it.second)max_v=it.second;
            }
            else {
                if(max_c<it.second)max_c=it.second;
            }

        }
        return max_c+max_v;
    }
};
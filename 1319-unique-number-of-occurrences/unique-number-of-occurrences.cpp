class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mpp;
        unordered_set<int>st;
        for(auto it:arr)mpp[it]++;
        for(auto it:mpp){
            if(st.find(it.second)!=st.end())return 0;
            st.insert(it.second);
        }
        return 1;

        
    }
};
class Solution {
public:
    int numSplits(string s) {
        unordered_map<char,int>mpp;
        int un=0;
        for(auto it:s){
            if(mpp.count(it)==0)un++;
            mpp[it]++;
        }
        int ans=0;
        int unl=0,unr=un;unordered_set<int>st;
        for(int i=0;i<s.size();i++){
            st.insert(s[i]);
            unl=st.size();
            if(mpp[s[i]]==1)
            {unr-=1;
            mpp.erase(s[i]);}
            else{
                mpp[s[i]]-=1;
            }
            if(unl==unr)ans++;
        }
        return ans;
    }
};
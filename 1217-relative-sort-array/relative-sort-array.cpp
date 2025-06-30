class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>ans;
        map<int,int>mpp;
        for(auto it:arr1){
            mpp[it]++;
        }
        for(auto it:arr2){
            if(mpp.find(it)!=mpp.end()){
                while(mpp[it]!=0){
                    ans.push_back(it);
                    mpp[it]--;
                }
                mpp.erase(it);
            }
        }
        for(auto it:mpp){
            while(it.second!=0)
            {ans.push_back(it.first);
            it.second--;}

        }
        return ans;

    }
};
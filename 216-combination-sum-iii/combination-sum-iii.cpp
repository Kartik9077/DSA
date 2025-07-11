class Solution {
public:
    void recc(int ind , int target ,int k , vector<vector<int>> &ans,vector<int> &ds){
        if(ind==10){
            if(ds.size()==k){
                if(target==0){
                    ans.push_back(ds);
                }
            }
                return;
        }
        if(ds.size()==k){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        if(target<=0) return;
        ds.push_back(ind);
        if(ind<=target) recc(ind+1,target-ind,k,ans,ds);
        ds.pop_back();
        recc(ind+1,target,k,ans,ds);


    }
    vector<vector<int>> combinationSum3(int k, int target) {
        vector<vector<int>> ans;
        vector<int>ds;
        recc(1,target,k,ans,ds);
        return ans;
    }
};
class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int>ans;
        vector<int>check(1001,0);
        for(int i=0;i<nums.size();i++){
            for(auto it:nums[i]){
                check[it]++;
            }
        }
        for(int i=0;i<1001;i++){
            if(check[i]==nums.size())ans.push_back(i);
        }
        return ans;
    }
};
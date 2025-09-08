class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        for(auto it:queries){
            int curr=0,i=0;
            for(i;i<nums.size();i++){
             if((curr+nums[i])<=it)curr+=nums[i];
             else break;
            }
            ans.push_back(i);
        }
        return ans;
    }
};
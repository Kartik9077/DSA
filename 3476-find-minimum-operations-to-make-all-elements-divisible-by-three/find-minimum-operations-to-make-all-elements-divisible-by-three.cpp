class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans=0;
    for(auto it:nums){
        if(it%3!=0)ans++;
    }
    return ans;
    }
};
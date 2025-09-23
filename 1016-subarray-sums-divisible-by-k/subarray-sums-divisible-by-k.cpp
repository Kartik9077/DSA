class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
       unordered_map<int,int>st;int ans=0;
       st[0]=1;int curr=0;
       for(auto it:nums){
         curr+=it;
        int p=curr%k;
        if(p<0)p+=k;
        ans+=st[p];
        st[p]++;
       }
       return ans;
    }
};
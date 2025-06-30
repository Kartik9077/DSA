class Solution {
public:
    int rec(int i,int last,vector<int>&arr1,vector<int>&arr2,map<pair<int,int>,int> &dp)
    {
        if(i==arr1.size())
        {
            return 0;
        }
        if(dp.count({i,last}))
        {
            return dp[{i,last}];
        }
        int ans=1e9;
        if(arr1[i]>last)
        {
            ans=rec(i+1,arr1[i],arr1,arr2,dp);
        }

        int u=upper_bound(arr2.begin(),arr2.end(),last)-arr2.begin();
        if(u<arr2.size())
        {
            ans=min(ans,1+rec(i+1,arr2[u],arr1,arr2,dp));
        }
        
        return dp[{i,last}]=ans;

    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        map<pair<int,int>,int> dp1,dp2;
        int x=rec(0,INT_MIN,arr1,arr2,dp1);
        return (x==1e9)?-1:x;
    }
};
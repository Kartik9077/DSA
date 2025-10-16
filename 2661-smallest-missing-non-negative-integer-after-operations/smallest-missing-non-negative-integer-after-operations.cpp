class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
         map<int, int> mp;int ans=0;
        for(auto i : nums) mp[((i % value) + value) % value]++;
        while(mp[ans % value]--) ans++;
        return ans;
    }
};
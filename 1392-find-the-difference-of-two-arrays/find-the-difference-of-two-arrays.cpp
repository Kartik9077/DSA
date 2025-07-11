class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>st1,st2;
        for(auto it:nums1)st1.insert(it);
        for(auto it:nums2)st2.insert(it);
        vector<vector<int>>ans(2,vector<int>());
        for(auto it:st1){
            if(st2.find(it)==st2.end())ans[0].push_back(it);
        }
        for(auto it:st2){
            if(st1.find(it)==st1.end())ans[1].push_back(it);
        }
        return ans;
    }
};
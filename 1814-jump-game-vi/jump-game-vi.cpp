class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        deque<pair<int,int>> q;
        q.push_back({nums[n-1],n-1});
        for(int i=n-2;i>=0;i--){
            while(!q.empty() && q.front().second>i+k) q.pop_front();
            int ans=nums[i]+q.front().first;
            while(!q.empty() && q.back().first<=ans) q.pop_back();
            q.push_back({ans,i});
        }
        return q.back().first;
    }
};
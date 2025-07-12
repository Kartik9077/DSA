class Solution {
public:
 struct myComp{
  bool operator()(
    pair<int,int>const& a,pair<int,int>const& b
  )
  {
    return a.second<b.second;
  }

 };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(k>nums.size())return nums;
        vector<int>ans;
        unordered_map<int,int>mpp;
        for(auto it:nums)mpp[it]++;

        priority_queue<pair<int,int>,vector<pair<int,int>>,myComp>pq;
        for(auto it:mpp){
            pq.push(make_pair(it.first,it.second));
        }
        while(!pq.empty()&&k){
            ans.push_back(pq.top().first);
            pq.pop();k--;
        }
        return ans;



        
    }
};
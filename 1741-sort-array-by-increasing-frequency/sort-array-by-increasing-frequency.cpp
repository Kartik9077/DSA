class Solution {
public: 
  static bool comp(pair<int,int>a,pair<int,int>b){
    if(a.second==b.second)return a>b;
    return a.second<b.second;
  }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(auto it:nums)mpp[it]++;
        nums.clear();
      vector<pair<int,int>>arr;
      for(auto it:mpp)arr.push_back({it.first,it.second});
      sort(arr.begin(),arr.end(),comp);
      for(auto it:arr){
        for(int i=0;i<it.second;i++)nums.push_back(it.first); 
      }
      return nums;
    }
};
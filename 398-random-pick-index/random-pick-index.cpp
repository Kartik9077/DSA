class Solution {
public: 
  unordered_map<int,set<int>>s;
    Solution(vector<int>& arr) {
        int n=arr.size();
       for(int i=0;i<arr.size();i++){
             s[arr[i]].insert(i);
       }
    }
    int pick(int val) {
         int a=s[val].size();
         int k=rand()%a;
         auto it=s[val].begin();
         advance(it,k);
         return *it;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
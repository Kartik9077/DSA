class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int check=0;
        vector<vector<int>>ans;
        vector<int>temp;
        while(check<=(1<<n)){
          int i=0;
          while(i<n){
            if(check&(1<<i)){
                temp.push_back(nums[i]);

            }
            i++;
          }
          ans.push_back(temp);
          temp.clear();
          check+=1;
        }
        ans.pop_back();
        return ans;

    }
};
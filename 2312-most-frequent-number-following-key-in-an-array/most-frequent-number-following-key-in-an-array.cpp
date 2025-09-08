class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        int ans=0;
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==key){
                mpp[nums[i+1]]++;

            }
        }
        int maxii=0;
        for(auto it:mpp){
            if(it.second>maxii){maxii=it.second;ans=it.first;
            }
            else if(it.second==maxii){
                maxii=0;
            }
        }
        return ans;
    }
};
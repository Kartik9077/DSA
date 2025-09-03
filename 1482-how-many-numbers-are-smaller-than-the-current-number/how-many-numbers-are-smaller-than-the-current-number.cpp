class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>k=nums;
        sort(k.begin(),k.end());
        unordered_map<int,int>mpp;
        for(int i=0;i<k.size();i++){
            if(i!=0&&k[i]==k[i-1])continue;
            else mpp[k[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            nums[i]=mpp[nums[i]];
        }
        return nums;
        
    }
};
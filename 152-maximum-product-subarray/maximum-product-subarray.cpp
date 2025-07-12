class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pro=1;
        int maxii=INT_MIN;
        for(int i=0;i<nums.size();i++){
            pro*=nums[i];
            maxii=max(maxii,pro);
            if(pro==0)pro=1;
        }
        pro=1;
        for(int i=nums.size()-1;i>=0;i--){
            pro*=nums[i];
            maxii=max(maxii,pro);
            if(pro==0)pro=1;
        }
        return maxii;
    }
};
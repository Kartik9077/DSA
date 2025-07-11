class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int>r(nums.size(),0),l(nums.size(),0);
        int sumr=0,suml=0;
        for(int i=1;i<nums.size();i++){
            sumr+=nums[i-1];
            r[i]=sumr;
        }
        for(int j=nums.size()-2;j>=0;j--){
            suml+=nums[j+1];
            l[j]=suml;
        }
        
        
        for(int i=0;i<nums.size();i++){
            if(l[i]==r[i])return i;
        }
        return -1;
    }
};
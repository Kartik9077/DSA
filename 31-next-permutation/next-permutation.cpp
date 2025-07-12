class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();bool k=false;
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                k=true;
                break;
            }
            
        }
        if(k==false){
            reverse(nums.begin(),nums.end());
            

         return;

        }
        int last_digit=nums[n-1]; int i=n-2;
        for( i=n-2;i>=0;i--){
            if(nums[i]<last_digit){
                break;

            }
            last_digit=nums[i];
        }
        if(i>=0){
            for(int k=nums.size()-1;k>i;k--){
                if(nums[k]>nums[i]){
                    swap(nums[k],nums[i]);
                    break;
                }
            }
         sort(nums.begin()+i+1,nums.end());
         
        }
        
        
    }
};
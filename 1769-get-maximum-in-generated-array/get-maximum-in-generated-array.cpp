class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> nums(n+1);
        
        for(int i = 0; i<((n+1)/2) ; i++){
            if( i == 0 ){
                nums[i] = 0;
                nums[i+1] = 1;
            }
            nums[2*i] = nums[i];
            nums[2*i + 1] = nums[i] + nums[i+1];
        }
        auto max = *max_element(nums.begin(),nums.end());
        return max;
        
    }
};
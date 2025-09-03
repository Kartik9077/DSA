class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n  = nums.size();
        sort(nums.begin(),nums.end());
        int maxp=0;
        for(int i =0;i<n-2;i++){
            int a = nums[i];
            int b = nums[i+1];
            int c = nums[i+2];

            if(a+b > c && b+c > a && c+a > b){
                int sum = a+b+c;
                maxp=max(maxp,sum);
            }
        }
        return maxp;
    }
};
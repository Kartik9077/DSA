class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        if(n==1) return 0;
        int maxa = 0;
        int maxa1 = maxa;
        int sum = 0;
        for(;true;){
            for(int i=0;i<=maxa && i<n;i++){
                maxa1 = max(maxa1,nums[i]+i);
            }
            if(maxa<maxa1){
                maxa = maxa1;
                sum++;
            }
            if(maxa >= nums.size()-1){
                break;
            }
        }
        return sum;
    }
};
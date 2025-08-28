class Solution {
public:
bool check(int a){
    if(a==2)return 1;
    if(a==1)return 0;
    if(a%2==0)return 0;
    for(int i=3;i<=sqrt(a);i+=2)if(a%i==0)return 0;
    return 1;
}
    int diagonalPrime(vector<vector<int>>& nums) {
        int n=nums.size()-1;
        int ans=0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<nums[0].size();j++){
                if(i==j || i+j==n){
                   if(check(nums[i][j]))ans=max(ans,nums[i][j]);
                }
            }

        }
        return ans;
    }
};
class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& div) {
        int maxi=-1; int ans=0;
        for( auto d:div){
            int cnt=0;
            for( auto num: nums){
                if(num%d==0){
                    cnt++;
                }
            }
            if(cnt>maxi){
                maxi=cnt;
                ans=d;
            }
            else if(cnt==maxi){
                ans=min(ans,d);
            }
        }
        return ans;
    }
};
class Solution {
public:

    int gcd(int a,int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }

    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int n=nums.size(),mx=*max_element(nums.begin(),nums.end());
        int ans=0;
        vector<bool>pre(mx+1,false);
        for(auto i:nums) pre[i]=1;

        for(int i=1;i<=mx;i++){
            int g=0;
            for(int j=i;j<=mx;j+=i){
                if(pre[j]) g=gcd(g,j);
                if(g==i) break;
            }
            if(g==i) ans++;
        }
        return ans; 
    }
};
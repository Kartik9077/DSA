#define ll long long

ll MOD=1e9+7;
class Solution {
public:


    ll dp[1002][1001],prefix[1002][1001];
     

    ll solvePrefix(int index,int k,int n){

        if(k<0) return 0;

        if(prefix[index][k]!=-1ll) return prefix[index][k];

        return prefix[index][k]=(solve(index,k,n)+ solvePrefix(index,k-1,n))%MOD;
    }
    ll solve(int index,int k,int n){

        if(k<0) return 0;
        if(index==n+1){
            if(k==0){
                return 1;
            }
            return 0;
        }
        

        if(dp[index][k]!=-1ll) return dp[index][k];

        int ans=0;
        ans+=((solvePrefix(index+1,k,n)-solvePrefix(index+1,k-index,n))%MOD+MOD)%MOD;

        return dp[index][k]=ans;

    }
    int kInversePairs(int n, int k) {
        
        memset(dp,-1,sizeof(dp));
        memset(prefix,-1ll,sizeof(prefix));

      //  if(k==0) return 1;
         
        return solve(1,k,n);

    }
};
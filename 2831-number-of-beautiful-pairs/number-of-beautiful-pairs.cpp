class Solution {
public:
bool check(int a,int b){
    while(b!=0)
    {
        long long  k=b;
        b=a%b;
        a=k;
    }
    return a==1;
}
  int f(int a){
    while(a>=10){
      a/=10;
    }
    return a;
  }
  int s(int a){
    return a%10;
  }
    int countBeautifulPairs(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(check(f(nums[i]),s(nums[j])))ans+=1;
            }
        }
        return ans;
    }
};
class Solution {
public:
  int callcm(int a,int b){
     long long lcm=(long long )a * (long long )b;
     lcm/=gcd(a,b);
     return (int)lcm;
  }
  int  check(int a,int b){
    while(a!=0){
        int t=a;
        a=b%a;
        b=t;
    }
    return b;
    // return gcd(a,b);
  }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        if(nums.size()<2)return nums;
        vector<int>ans;
        for(int i=1;i<nums.size();i++){
            int num1=nums[0];
            if(!ans.empty())num1=ans.back();
            int num2=nums[i];
            if(check(num1,num2)>1){
                if(!ans.empty())ans.pop_back();
                ans.push_back(callcm(num1,num2));
                while(ans.size()>=2&&check(ans[ans.size()-1],ans[ans.size()-2])>1){
                    int k=ans[ans.size()-1],l=ans[ans.size()-2];
                   ans.pop_back(),ans.pop_back();
                   ans.push_back(callcm(k,l));
                }
            }
            else{
                if(ans.size()==0)ans.push_back(num1);
             ans.push_back(num2);
             while(ans.size()>=2&&check(ans[ans.size()-1],ans[ans.size()-2])>1){
                    int k=ans[ans.size()-1],l=ans[ans.size()-2];
                   ans.pop_back(),ans.pop_back();
                   ans.push_back(callcm(k,l));
                }
            }
        }
        return ans;
    }
};
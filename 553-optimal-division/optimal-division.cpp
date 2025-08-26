class Solution {
public:
    string optimalDivision(vector<int>& nums) {
         string ans="";
        if(nums.size()<=2){
         for(int i=0;i<nums.size();i++){
            ans+=to_string(nums[i]);
            if(i!=nums.size()-1)ans+="/";
         }
         return ans;

        }

       
        bool k=0;
        for(auto it:nums){
        ans+=to_string(it);
        ans+="/";
        if(!k){
            k=1;
            ans+="(";
        }

        }
        if(ans.size()==3)ans.erase(ans.size()-1,1);
        ans.erase(ans.size()-1,1);
        if(ans.size()>=2)ans+=")";
        return ans;

    }
};
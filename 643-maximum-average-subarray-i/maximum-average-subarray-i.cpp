class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if(nums.size()<k){
            return double(nums[0]);
        }
        if(nums.size()==1){
            if(k==1){
                return double(nums[0]);
            }
        }

        int curr_len=1;
        int start=0,end=1;
          double  curr_num=nums[0];double avg_ans=INT_MIN;
          while(end<=nums.size()&&start<nums.size()){
            if(curr_len<k){
                curr_num+=nums[end];
                curr_len=end-start+1;
                end++;
            }
            else if(curr_len==k)
            {
                avg_ans=max(avg_ans,double(curr_num));
                curr_num-=nums[start];start++;
                curr_len-=1;

            }
          }
        
        return avg_ans/k;
        

        
    }
};
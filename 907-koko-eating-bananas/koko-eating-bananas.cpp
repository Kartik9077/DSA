class Solution {
public:
double func(vector<int>&nums,int mid)
{  double ans=0;
    for(int i=0;i<nums.size();i++)
    {   
        ans+=ceil((double)nums[i]/(double)mid);
    }
    return ans;
}
    int minEatingSpeed(vector<int>& nums, int h) {
        int no;
        int n=nums.size();
        if(nums.size()==1)
        {
            if(nums[0]%h>0)
            {
                return (nums[0]/h)+1;
            }
            else
            return nums[0]/h;
        }

        int low=1;int high=*max_element(nums.begin(),nums.end());
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(func(nums,mid)<=h)
            {  
                no=mid;
                high=mid-1;

            }
            else
            {
                low=mid+1;
            }
        }
        return no;

    }
};
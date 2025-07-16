class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int c=nums[0]%2,odd=0,even=0,both=0;
        for(auto it:nums){
            if(it%2==0)even++;
            else odd++;
            if(it%2==c){both++;c=abs(c-1);}
        }
        return max(both,max(odd,even));
    }
};
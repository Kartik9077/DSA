class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a=INT_MAX,b=INT_MAX;
        for(auto it:nums){
            if(it<=a)a=it;
            else if(it<=b)b=it;
            else return 1;
        }
        return 0;

        
    }
};
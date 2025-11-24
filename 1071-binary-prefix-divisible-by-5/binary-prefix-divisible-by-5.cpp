class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
      vector<bool>v;
        int a=0;
        for(int i:nums)
        {
            a=((a*2)+i)%5;
            if(a==0)
            v.push_back(true);
            else
            v.push_back(false);
        }
      return v;
    }
};
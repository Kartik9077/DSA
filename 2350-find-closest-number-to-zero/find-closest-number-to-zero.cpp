class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int pos=-1,dis=INT_MAX;
        for(auto it:nums){
            if(dis>=abs(it-0)){
                if(dis==abs(it-0)&& pos<it)pos=it;
                else {
                    if(dis>abs(it-0))pos=it;
                }
                dis=abs(it-0);

            }
        }
        return pos;
    }
};
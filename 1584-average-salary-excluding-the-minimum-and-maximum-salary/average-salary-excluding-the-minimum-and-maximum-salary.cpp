class Solution {
public:
    double average(vector<int>& salary) {
            double sum=0;
        int maxe=INT_MIN,mine=INT_MAX;
        for(int i:salary){
              sum+=i;
              maxe= max(maxe,i);
              mine= min(mine,i);
        }
        return (sum-maxe-mine)/(salary.size()-2);
    }
};
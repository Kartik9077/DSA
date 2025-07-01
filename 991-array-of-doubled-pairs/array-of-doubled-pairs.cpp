class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
       unordered_map<int,int>mpp;
       for(auto it:arr){
        mpp[it]++;
       }
        sort(arr.begin(), arr.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });
       for(auto x:arr){
        if(mpp[x]==0)continue;
        if(mpp[2*x]==0)return 0;
        mpp[x]--;
        mpp[2*x]--;

       }
       return 1;
    }
};
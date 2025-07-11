class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int>arr(n+1,0);
        for(int i=0;i<gain.size();i++){
            arr[i+1]=gain[i]+arr[i];
        }
        return *max_element(arr.begin(),arr.end());
        
    }
};
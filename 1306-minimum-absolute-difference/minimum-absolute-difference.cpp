class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
       vector<vector<int>>ans;
       int curr=INT_MAX;
       for(int i=1;i<arr.size();i++){
        if(abs(arr[i]-arr[i-1])==curr)ans.push_back({arr[i-1],arr[i]});
        else if(abs(arr[i]-arr[i-1])<curr){
            ans.clear();
            curr=abs(arr[i]-arr[i-1]);
            ans.push_back({arr[i-1],arr[i]});
        }

       }
       return ans;
        
    }
};
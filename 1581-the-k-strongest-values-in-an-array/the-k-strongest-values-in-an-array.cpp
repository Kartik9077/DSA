class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        if(!is_sorted(arr.begin(),arr.end())){
            sort(arr.begin(),arr.end());
        }
        int m=((arr.size()-1)/2);
        int j=0;
        int i=arr.size()-1;
        vector<int> res;
        while(j<=i){
            if(abs(arr[i]-arr[m])>abs(arr[j]-arr[m])){
                res.push_back(arr[i]);
                i--;
            }
            else if(abs(arr[i]-arr[m])==abs(arr[j]-arr[m])){
                if(arr[i]>arr[j]){
                    res.push_back(arr[i]);
                    i--;
                }
                else{
                 res.push_back(arr[j]);
                 j++;
                }
            }
            else{
                res.push_back(arr[j]);
                j++;
            }
            
        }
        res.erase(res.begin()+k,res.end());
        return res;
    }
};
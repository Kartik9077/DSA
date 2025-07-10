class Solution {
public:
    int longestMountain(vector<int>& arr) {
       int countl=0,countr=0,ans=0;
       for(int i=1;i<arr.size()-1;i++){
         if(arr[i]<=arr[i-1]||arr[i]<=arr[i+1])continue;
         else{
            countl=0,countr=0;
            for(int p=i-1;p>=0;p--){
                if(arr[p]<arr[p+1])countl++;
                else break;
            }
            for(int p=i+1;p<arr.size();p++){
                if(arr[p]<arr[p-1])countr++;
                else break;
            }
            ans=max(ans,1+countr+countl);
         }
         
       }
       return ans;

    }
};
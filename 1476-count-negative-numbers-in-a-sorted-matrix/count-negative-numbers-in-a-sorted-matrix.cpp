class Solution {
public:
    int countNegatives(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        int s = 0;
        int e = m-1;
        int numbers = 0;
        for(int i=0;i<n;i++){
            int index = 0;
            bool found = false;
            s = 0;
            e = m-1;
            while(s<=e){
                int mid = s+((e-s)/2);
                if(arr[i][mid]>=0){
                    s=mid+1;
                }else if(arr[i][mid]<0){
                    found = true;
                    index = mid;
                    e = mid-1;
                } 
            }
            if(found == true){
                numbers += m-index;
            }  
        }
        return numbers;
    }
};
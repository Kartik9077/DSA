class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
           int i=0;
        while(i<arr.size()){
            int j=0;
            while(j<pieces.size()){
                if(arr[i]==pieces[j][0]){
                    break;
                }
                j++;
            }
            if(j==pieces.size())return 0;
            int found=0;
           int k=0;
           while(k<pieces[j].size()){
            if(pieces[j][k]!=arr[i]){
                found=1;
                break;
            }
            i++;
            k++;
           }
           if(found) return 0;
        }
        return 1;
    }
};
class Solution {
public:
    vector<int> plusOne(vector<int>& arr) {
        bool k=1;vector<int>more_ans;
        for(int i=arr.size()-1;i>=0;i--){
            if(i==0&&arr[i]==9){
                k=0;
                break;
            }
            if(arr[i]==9){arr[i]=0;}
            else{
                arr[i]+=1;
                break;
            }
        }
        if(k==0){
          more_ans.push_back(1);
          for(auto it:arr){
            more_ans.push_back(0);
          }
          return more_ans;
        }
        return arr;

    }
};
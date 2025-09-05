class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        for(int i=0;i<target.size();i++){
            int start=i;
            if(arr[i]!=target[i]){
                int end=i;
                for(int j=i+1;j<arr.size();j++){
                    if(arr[j]!=target[start])continue;
                    else end=j;
                }
                if(end==i)return 0;
                reverse(arr.begin()+start,arr.begin()+end+1);
            }
        }
        return 1;
    }
};
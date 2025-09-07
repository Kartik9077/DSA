class Solution {
public:
    vector<int> sumZero(int n) {
        if(n==1)return {0};
        vector<int>v;
        if(n%2!=0){
            for(int i=-n/2;i<n/2+1;i++){
                v.push_back(i);
            }
        }
        else{
            for(int i=-n/2;i<n/2+1;i++){
                if(i==0){
                    continue;
                }
                v.push_back(i);
            } 
        }
        return v;
    }
};
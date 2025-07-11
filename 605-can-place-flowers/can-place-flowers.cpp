class Solution {
public:
    bool canPlaceFlowers(vector<int>& fl, int n) {
        int k=fl.size();
        if(n==0)return 1;
        int ans=0;
        if(n>fl.size())return 0;
        if(fl.size()==1&&fl[0]==0&&n<=1)return 1;
        else if(fl[0]==1&&fl.size()==1)return 0;
        for(int i=0;i<k;i++){
            if(i==0){
                if(fl[i]==0&&fl[i+1]==0){
                    ans++;
                    fl[i]=1;
                }
            }
            else if(i==k-1){
                if(fl[i]==0&&fl[i-1]==0)ans++;

            }
            else{
                if(fl[i]==0&&fl[i-1]==0&&fl[i+1]==0){
                    ans++;
                    fl[i]=1;
                }
            }

        }
        return ans>=n;
    }
};
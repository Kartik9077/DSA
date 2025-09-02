class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());int j=0;
        int ans=0;
        for(int i=piles.size()-1;i>j;i-=2){
            if((i-j+1)>=3)ans+=piles[i-1];
            j++;
        }
        return ans;
    }
};
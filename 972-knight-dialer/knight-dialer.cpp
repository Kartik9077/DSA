class Solution {
public:
static const int mod=1e9+7;
int cache[5001][10];
vector<vector<int>>moves={ {4, 6},{8, 6},{7, 9},{4, 8},{3, 9, 0},{},{0, 1, 7},{2, 6},{1, 3},{2, 4}};
    int knightDialer(int n) {
        vector<int>ne={0,1,2,3,4,5,6,7,8,9};
        return k(n,ne); 
    }
    int k(int rem,vector<int>&ne){
        if(rem==1)return ne.size();
        int co=0;
        for(int n:ne){
            int curr=cache[rem][n];
            if(curr==0){
                curr=k(rem-1,moves[n]);
                cache[rem][n]=curr;
            }
            co+=curr;
            co%=mod;

        }
        return co;
    }
};
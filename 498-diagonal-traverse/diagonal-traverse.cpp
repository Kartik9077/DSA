class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int>ans;
        vector<int>curr;
        int i=0,j=0;int z=-1;
        while(i<mat.size()&&j<mat[0].size()){
            z+=1;
            int k=i,p=j;
            while(k<mat.size()&&p>=0){
                curr.push_back(mat[k][p]);
                k++;p--;
            }
            if(z%2==0)reverse(curr.begin(),curr.end());
            for(auto it:curr)ans.push_back(it);
            curr.clear();
            if(j+1==mat[0].size())i++;
            else j++;
        }
        return ans;
    }
};
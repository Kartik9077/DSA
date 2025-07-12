class Solution {
    vector<int>solve(int row){
        long long ans=1;
        
        vector<int>temp;
        temp.push_back(1);
        for(int col=1;col<row;col++){
         ans=ans*(row-col);
            ans=ans/col;
            temp.push_back(ans);
            
            
            }
        return temp;
}
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(solve(i));
}
        return ans;
        
    }
};
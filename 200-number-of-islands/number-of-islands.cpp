class Solution {
public:
  void solve(int i,int j,vector<vector<char>>&grid){
    if(i>=grid.size()||i<0||j>=grid[0].size()||j<0||grid[i][j]=='0')return;
    grid[i][j]='0';
    solve(i,j+1,grid);solve(i,j-1,grid);solve(i+1,j,grid);solve(i-1,j,grid);


  }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!='0'){
                    ans+=1;
                    solve(i,j,grid);
                }

            }

        }
        return ans;
    }
};
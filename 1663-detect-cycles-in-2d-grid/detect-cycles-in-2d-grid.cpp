class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    bool dfs(int row,int col,int parrow,int parcol,char ch,vector<vector<int>>& vis,vector<vector<char>>& grid){
        vis[row][col]=1;

        for(int i=0;i<4;i++){
            int newr=row+dr[i];
            int newc=col+dc[i];
            if(newr>=0 && newr<grid.size() && newc>=0 && newc<grid[0].size() && vis[newr][newc]==0 && grid[newr][newc]==ch){
                if(dfs(newr,newc,row,col,ch,vis,grid)) return true;
            }
            else if(newr>=0 && newr<grid.size() && newc>=0 && newc<grid[0].size() && vis[newr][newc]==1 && (newr!=parrow || newc!=parcol) && grid[newr][newc]==ch){
                return true;
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j])
                if(dfs(i,j,-1,-1,grid[i][j],vis,grid)) return true;
            }
        }
        return false;
    }
};
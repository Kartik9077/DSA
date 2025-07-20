class Solution {
public:  
  void dfs(vector<vector<char>>& board,int i,int j){
  if (i<0 || i>=board.size() || j<0 || j>=board[0].size() ) return;
        if (board[i][j]=='.') return;
        board[i][j]='.';
        dfs(board, i-1, j);
        dfs(board, i+1, j);
        dfs(board, i, j-1);
        dfs(board, i, j+1);

  }
    int countBattleships(vector<vector<char>>& board) {
        int ans=0,n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='X'){
                    ans++;
                    dfs(board,i,j);
                }
            }
        }
        return ans;
        
    }
};
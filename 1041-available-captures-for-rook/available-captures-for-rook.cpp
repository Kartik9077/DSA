class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int a=0,b=0,ans=0;
        for(int i=0;i<board.size();i++)
        for(int j=0;j<board[0].size();j++){
            if(board[i][j]=='R'){
                a=i,b=j;break;
            }
  
        }
        for(int i=a-1;i>=0;i--){
            if(board[i][b]=='p')
            {
                ans++;break;
            }
            else if(board[i][b]=='.')continue;
            else break;
        }
         for(int i=a+1;i<board.size();i++){
            if(board[i][b]=='p'){
                ans++;break;
            }
            else if(board[i][b]=='.')continue;
            else break;
        }
         for(int i=b-1;i>=0;i--){
            if(board[a][i]=='p'){
                ans++;break;
            }
            else if(board[a][i]=='.')continue;
            else break;
        }
        for(int i=b+1;i<board[0].size();i++){
            if(board[a][i]=='p'){
                ans++;break;
            }
            else if(board[a][i]=='.')continue;
            else break;
        }
        return ans;


    }
};
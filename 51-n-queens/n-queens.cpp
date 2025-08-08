class Solution {
public:
    bool check_diagonal(int row,int col,vector<string>temp,int n){
        int i=row,j=col;
       while(i>-1&&j>-1){
        if(temp[i][j]!='.')return 0;
        i--;j--;
       }
       i=row,j=col;
       while(i>-1&&j<n){
        if(temp[i][j]!='.')return 0;
        i--;j++;

       }
       return 1;
    }
  void solve(int n,vector<string>&temp,vector<vector<string>>&ans,vector<bool>&column,int row){
    if(row==n){
        ans.push_back(temp);
        return;
    }
    for(int j=0;j<n;j++){
        if(column[j]==0&&check_diagonal(row,j,temp,n)){
            column[j]=1;
            temp[row][j]='Q';
            solve(n,temp,ans,column,row+1);
            temp[row][j]='.';
            column[j]=0;
        }
    }

  }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>temp(n);
        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        temp[i].push_back('.');
        }
        }
        vector<bool>column(n,0);
        solve(n,temp,ans,column,0);
        return ans;



    }
};
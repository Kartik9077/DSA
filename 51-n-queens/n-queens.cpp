class Solution {
public:
    // bool check_diagonal(int row,int col,vector<string>temp,int n){
    //     int i=row,j=col;
    //    while(i>-1&&j>-1){
    //     if(temp[i][j]!='.')return 0;
    //     i--;j--;
    //    }
    //    i=row,j=col;
    //    while(i>-1&&j<n){
    //     if(temp[i][j]!='.')return 0;
    //     i--;j++;

    //    }
    //    return 1;
    // }
  void solve(int n,vector<string>&temp,vector<vector<string>>&ans,vector<bool>&column,int row,vector<int>&st,vector<int>&lt){
    if(row==n){
        ans.push_back(temp);
        return;
    }
    for(int j=0;j<n;j++){
        if(column[j]==0&&st[row+j]==0&&lt[n-1+j-row]==0){
            column[j]=1;
            temp[row][j]='Q';
            st[row+j]=1;
            lt[n-1+j-row]=1;
            solve(n,temp,ans,column,row+1,st,lt);
            st[row+j]=0;
            lt[n-1+j-row]=0;
            temp[row][j]='.';
            column[j]=0;
        }
    }

  }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>temp(n);
       vector<int>st(2*n-1,0),lt(2*n-1,0);
        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        temp[i].push_back('.');
        }
        }
        vector<bool>column(n,0);
        solve(n,temp,ans,column,0,st,lt);
        return ans;



    }
};
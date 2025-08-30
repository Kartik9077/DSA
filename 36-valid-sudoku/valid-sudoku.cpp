class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
      unordered_set<char>rows[9];
      unordered_set<char>colums[9];
      unordered_set<char>grid[9];
      for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
          if(board[i][j]=='.')continue;
          char value=board[i][j];
          int pos=(i/3) * 3+j/3;
          if(rows[i].count(value)||colums[j].count(value)||grid[pos].count(value)){
            return 0;
          }
          rows[i].insert(value);
          colums[j].insert(value);
          grid[pos].insert(value);
        }
      }
      return 1;

        
    }
};
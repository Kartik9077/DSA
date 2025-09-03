class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int Arow[3] = {0}, Acol[3] = {0}, Adiag1 = 0, Adiag2 = 0;
        int Brow[3] = {0}, Bcol[3] = {0}, Bdiag1 = 0, Bdiag2 = 0;

        for (int i = 0; i < moves.size(); i++) {
            int row = moves[i][0];
            int col = moves[i][1];
            
            if (i % 2 == 0) {
                Arow[row]++;
                Acol[col]++;
                
                if (row == col) {
                    Adiag1++;
                }
                
                if (row + col == 2) {
                    Adiag2++;
                }
                
                if (i >= 4) {
                    if (Arow[row] == 3 || Acol[col] == 3 || Adiag1 == 3 || Adiag2 == 3) {
                        return "A";
                    }
                }
                
            } else {
                Brow[row]++;
                Bcol[col]++;
                
                if (row == col) {
                    Bdiag1++;
                }
                
                if (row + col == 2) {
                    Bdiag2++;
                }
                
                if (i >= 4) {
                    if (Brow[row] == 3 || Bcol[col] == 3 || Bdiag1 == 3 || Bdiag2 == 3) {
                        return "B";
                    }
                }
            }
        }
        
        if (moves.size() == 9) {
            return "Draw";
        }
        
        return "Pending"; 
    }
};
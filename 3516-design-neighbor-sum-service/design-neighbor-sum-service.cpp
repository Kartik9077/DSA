class NeighborSum {
private:
    vector<vector<int>> grid;
    int rows, cols;
    const int dra[4] = {-1, 0, 1, 0}, dca[4] = {0, 1, 0, -1};
    const int drd[4] = {-1,-1,1,1}, dcd[4] = {-1,1,1,-1};
    vector<pair<int,int>>decodeIndices;
public:
    NeighborSum(vector<vector<int>>& grid) {
        this -> grid = grid;
        rows = grid.size();
        cols = grid[0].size();
        decodeIndices.resize(rows*cols);
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                decodeIndices[grid[r][c]] = {r, c};
            }
        }
    }
    
    int adjacentSum(int value) {
        int ans = 0;
        int row = decodeIndices[value].first;
        int col = decodeIndices[value].second;
        for(int i=0; i<4; i++){
            int nr = row + dra[i];
            int nc = col + dca[i];
            if(nr>=0 && nr<rows && nc>=0 && nc<cols) ans += grid[nr][nc];
        }
        return ans;
    }
    
    int diagonalSum(int value) {
        int ans = 0;
        int r = decodeIndices[value].first;
        int c = decodeIndices[value].second;
        for(int i=0; i<4; i++){
            int nr = r + drd[i];
            int nc = c + dcd[i];
            if(nr>=0 && nr<rows && nc>=0 && nc<cols) ans += grid[nr][nc];
        }
        return ans;
    }
};
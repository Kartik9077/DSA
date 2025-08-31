class Solution {
public:

    int n, m;
    vector<string> Grid;
    int CatJump;
    int MouseJump;
    pair<int,int> FoodPos;
    vector<int> x_dir = {0,0,1,-1};
    vector<int> y_dir = {1,-1,0,0};
    int dp[8][8][8][8][102];

    bool Safe(int x, int y){
        if (x >= 0 && y >= 0 && x < n && y < m) return Grid[x][y] != '#';
        return false;
    }

    int Solve(pair<int,int> catPos, pair<int,int> ratPos, int turn, int moves){

        if(dp[catPos.first][catPos.second][ratPos.first][ratPos.second][moves] != -1){
            return dp[catPos.first][catPos.second][ratPos.first][ratPos.second][moves];
        }

        if(moves > 100) return 1;
        if(catPos.first == ratPos.first && catPos.second == ratPos.second) return 1;
        if(catPos.first == FoodPos.first && catPos.second == FoodPos.second) return 1;
        if(ratPos.first == FoodPos.first && ratPos.second == FoodPos.second) return 0;

        int x, y, maxSteps;

        if(turn){
            x = catPos.first;
            y = catPos.second;
            maxSteps = CatJump;           
        }else{
            x = ratPos.first;
            y = ratPos.second;
            maxSteps = MouseJump;
        }

        for(int dir=0;dir<4;dir++){
            for(int step=0;step<=maxSteps;step++){
                int x_new = x + (step * x_dir[dir]);
                int y_new = y + (step * y_dir[dir]);

                if(!Safe(x_new, y_new)) break;

                if(turn){
                    int temp = Solve({x_new,y_new},ratPos,1-turn,moves+1);
                    if(temp == 1){
                        return dp[catPos.first][catPos.second][ratPos.first][ratPos.second][moves] = 1;
                    }
                }else{
                    int temp = Solve(catPos,{x_new,y_new},1-turn,moves+1);
                    if(temp == 0){
                        return dp[catPos.first][catPos.second][ratPos.first][ratPos.second][moves] = 0;
                    }
                }
            }
        }

        return dp[catPos.first][catPos.second][ratPos.first][ratPos.second][moves] = 1-turn;

    }

    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
        n = grid.size();
        m = grid[0].size();
        Grid = grid;
        CatJump = catJump;
        MouseJump = mouseJump;
        memset(dp, -1, sizeof(dp));

        pair<int,int> catPos, ratPos;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='C') catPos = {i,j};
                else if(grid[i][j]=='M') ratPos = {i,j};
                else if(grid[i][j]=='F') FoodPos = {i,j};
            }
        }

        return Solve(catPos, ratPos, 0, 1) == 0;
    }
};
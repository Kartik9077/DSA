class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coord) {
        if (coord.size() <= 2) return true;

        if (coord[1][0] == coord[0][0]) {
            int x0 = coord[0][0];
            for (int i = 0; i < (int)coord.size(); i++) {
                if (coord[i][0] != x0) return false;
            }
            return true;
        }

        double m = (double)(coord[1][1] - coord[0][1]) / (coord[1][0] - coord[0][0]);

        double c = 0.0;
        bool haveC = false;
        for (int i = 0; i < (int)coord.size(); i++) {
            if (coord[i][0] == 0) {
                c = coord[i][1];
                haveC = true;
                break;
            }
        }
        if (!haveC) {
            c = coord[0][1] - m * coord[0][0];
        }

        const double EPS = 1e-9;
        for (int k = 0; k < (int)coord.size(); k++) {
            int x = coord[k][0];
            int y = coord[k][1];
            if (fabs((m * x + c) - y) > EPS) return false;
        }
        return true;
    }
};
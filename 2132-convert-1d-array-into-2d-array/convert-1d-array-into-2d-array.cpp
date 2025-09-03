class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int total = original.size();
        if( total != m*n){
            return {};
        }

        vector<vector<int>> resultArr(m,vector<int>(n));
        for(int i = 0 ; i < total ; i++){
            resultArr[i/n][i%n] = original[i];
        }
        return resultArr; 
    }
};
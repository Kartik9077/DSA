class Solution {
public:
    map<int,int>maps;
    bool call(int i,vector<vector<int>>& matrix){
        map<int,int>rightleft;
        map<int,int>bottomtop;
        for(int j=0;j<matrix.size();j++){
            rightleft[matrix[i][j]]++;
            if(rightleft[matrix[i][j]] > 1){
                return false;
            }
            bottomtop[matrix[j][i]]++;
            if(bottomtop[matrix[j][i]] >1){
                return false;
            }

        }
        return true;
    }
    bool checkValid(vector<vector<int>>& matrix) {
        map<int,int>maps;
        int n = matrix.size();
        for(int i=0;i<n;i++){
            if(!call(i,matrix)){
                return false;
            }
        }

        return true;
    }
};
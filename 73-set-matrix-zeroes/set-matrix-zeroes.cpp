class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size(),j,i;
         int check=0;
         for( i=0;i<n;i++)
            for( j=0;j<m;j++)
            if(matrix[i][j]==0){
                matrix[i][0]=0;
                if(j!=0)
                    matrix[0][j]=0;
                
                else
                    check=1;
                
            }


            for(i=1;i<n;i++)
            for(j=1;j<m;j++)
            if(matrix[0][j]==0||matrix[i][0]==0)
            matrix[i][j]=0;

         if(matrix[0][0]==0)
         for(int j=0;j<m;j++)
            matrix[0][j]=0;
         
         if(check)
            for( i=0;i<n;i++)
                matrix[i][0]=0;


         return;


    }
};
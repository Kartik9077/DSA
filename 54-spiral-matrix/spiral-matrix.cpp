class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matr) {
        vector<int>matrix;
        int n=matr.size();
        int m=matr[0].size();
        int left=0;
        int right=m-1;
  int top=0;
  int bottom=n-1;
   while(top<=bottom&&left<=right)
   {
     for(int j=left;j<=right;j++)
     {
        matrix.push_back(matr[top][j]);

     }
     top++;
     for(int i= top;i<=bottom;i++)
     {
        matrix.push_back(matr[i][right]);
     }
     right--;
     if(top<=bottom)
     {
     for(int j=right;j>=left;j--)
     {
        matrix.push_back(matr[bottom][j]);
     }
     bottom--;
   }
     if(left<=right)
     {
     for(int i=bottom;i>=top;i--)
     {
        matrix.push_back(matr[i][left]);
     }
left++;
     }
   }
     return matrix;   
    }
};
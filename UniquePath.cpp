*/ Given a grid of size m * n, lets assume you are starting at (1,1) and your goal is to reach (m,n). At any instance, if you are on (x,y), you can either go to (x, y + 1) or (x + 1, y).

Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Lucas Mendes

FACEBOOK

*/

int uniquePathsWithObstacles(vector<vector<int> > &A) {

    int row = A.size();
    int col = A[0].size();
    
    int cur = -1;
    int table[row+1][col + 1];
    
    if(A[0][0] == 1)
    {
        return 0;
    }
    else
    {
        table[0][0] = 1;
    }
    
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
        {
            if(i != 0 || j != 0)
                table[i][j] = 0;
            
            if(i - 1 >= 0)
                table[i][j] += table[i -1][j];
            
            if(j - 1 >= 0)
                table[i][j] += table[i][j -1];
                
            if(A[i][j] == 1)
            {
                table[i][j] = 0;
            }
            
       // cout << table[i][j] << " ";

        }
        
    return table[row - 1][col - 1];
    
}

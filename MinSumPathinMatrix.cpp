nt Solution::minPathSum(vector<vector<int> > &A) {
    
    // Size of Matrix
    int row = A.size();
    int col = A[0].size();
    
    // Table for Memoization
    int table[row + 1][col + 1];
    
    // Loop through the entire Matrix
    for(int i = 0; i < A.size(); i++)
        for(int j = 0; j < A[i].size(); j++)
        {
            // If path from left and up is possible, check the optimal one 
            if(i - 1 >= 0 && j - 1 >= 0 )
                table[i][j] = A[i][j] + min(table[i - 1][j], table[i][j -1 ]);
            // If only path from up is possible
            else if(i - 1 >= 0)
                table[i][j] = A[i][j] + table[i -1][j];
            // If only path from left is possible
            else if(j - 1 >= 0)
                table[i][j] = A[i][j] + table[i][j - 1];
            // If cur is at top corner left ==> [0][0]
            else
                table[i][j] = A[i][j];
        }
        
    return table[row - 1][col -1];
}

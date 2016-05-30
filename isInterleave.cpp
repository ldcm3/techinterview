*/
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

Lucas Mendes

GOOGLE

*/


int isInterleave(string A, string B, string C) {
   
    int lenA = A.length();
    int lenB = B.length();
    
    bool table[lenA + 1][lenB + 1];
   
    memset(table, 0, sizeof(table));
    
    if(lenA + lenB != C.length())
        return false;
    
    
    for(int i = 0; i <= lenA; i++)
    {
        for(int j = 0; j <= lenB; j++)
        {
            if (i==0 && j==0)
                table[i][j] = true;
            else if(i == 0 && B[j-1] == C[j-1])
                table[i][j] = table[i][j-1];
            else if(j == 0 && A[i-1] == C[i-1])
                table[i][j] = table[i-1][j];
                
            // Current character of C matches with current character of A,
            // but doesn't match with current character of B
            else if(A[i-1]==C[i+j-1] && B[j-1]!=C[i+j-1])
                table[i][j] = table[i-1][j];
 
            // Current character of C matches with current character of B,
            // but doesn't match with current character of A
            else if (A[i-1]!=C[i+j-1] && B[j-1]==C[i+j-1])
                table[i][j] = table[i][j-1];
 
            // Current character of C matches with that of both A and B
            else if (A[i-1]==C[i+j-1] && B[j-1]==C[i+j-1])
                table[i][j]=(table[i-1][j] || table[i][j-1]) ;
        }
    }
    
    return table[lenA][lenB];
}

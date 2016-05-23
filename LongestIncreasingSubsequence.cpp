*/ Find the longest increasing subsequence of a given sequence / array.

Lucas Mendes

FACEBOOK

*/

int lis(const vector<int> &A) {
   
   
    int table[A.size() + 1];
    int max = -1;

    // Initialize table with 1's    
    for (int i = 0; i < A.size(); i++ )
        table[i] = 1;
    
    for(int i = 1; i < A.size() ; i++)
    {
        for(int j = 0; j < i ; j++)
        {
            if(A[i] > A[j] && table[i] < table[j] + 1)
                table[i] = table[j] + 1;
        }
    }
    
    
    for (int i = 0; i < A.size(); i++ )
        if (max < table[i])
            max = table[i];
            
    return max;
}

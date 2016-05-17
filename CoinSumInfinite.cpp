/* You are given a set of coins S. In how many ways can you make sum N assuming you have infinite amount of each coin in the set.

Lucas Mendes

MICROSOFT

*/

int solve(vector<int> S, int m, int n)
{
     // table[i] will be storing the number of solutions for
    // value i. We need n+1 rows as the table is consturcted
    // in bottom up manner using the base case (n = 0)
    int table[n+1];
 
    // Initialize all table values as 0
    memset(table, 0, sizeof(table));
 
    // Base case (If given value is 0)
    table[0] = 1;
 
    // Pick all coins one by one and update the table[] values
    // after the index greater than or equal to the value of the
    // picked coin
    for(int i=0; i<m; i++)
        for(int j=S[i]; j<=n; j++)
            table[j] += table[j-S[i]] % 1000007;
 
    return table[n] % 1000007;
}


int coinchange2(vector<int> &A, int B) {
    
    return solve(A,A.size(),B) % 1000007;
}

*/
Given two sequences S, T, count number of unique ways in sequence S, to form a subsequence that is identical to the sequence T.

Lucas Mendes

GOOGLE

*/

int numDistinct(string S, string T) {
   	  int lens = S.length(), lent = T.length();
         if(lent == 0)return 1;
         else if(lens == 0)return 0;
         int dp[lens+1][lent+1];
         memset(dp, 0 , sizeof(dp));
         for(int i = 0; i <= lens; i++)dp[i][0] = 1;
         
         for(int i = 1; i <= lens; i++)
         {
             for(int j = 1; j <= lent; j++)
             {
                 if(S[i-1] == T[j-1])
                     dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
                 else dp[i][j] = dp[i-1][j];
             }
         }
         return dp[lens][lent];
     }

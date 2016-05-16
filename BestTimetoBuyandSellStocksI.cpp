*/ Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Lucas Mendes
FACEBOOK

*/

int maxProfit(const vector<int> &A) {
  
    if(A.size() == 0)
        return 0;
   
    int minn = A[0];
    int maxx= 0;
    
    
    for(int i =1 ;i < A.size(); i++)
    {
        if(A[i] - minn > maxx)
            maxx = A[i] - minn;
            
        else
        {
            if(A[i] < minn)
                minn = A[i];
        }
    }
    
    return maxx;
}

*/ 
  
    Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
    The same repeated number may be chosen from C unlimited number of times.
    
    FACEBOOK
    
    Lucas Mendes

*/

void helper(int start,int target, int sum , vector<int> A, vector<int> &tmp, vector<vector<int> > &ans)
{
    // Target reached
    if( sum == target)
    {
        ans.push_back(tmp);
        return;
    }
    else if(sum > target || start >= A.size())
    {
        return ;
    }
    else
    {
        for(int i = start; i < A.size(); i++)
        {
            // Do not repeate values in the same loop
            if(i > start && A[i] == A[i - 1])
                continue;
                
            tmp.push_back(A[i]);
            // Check the sum of the same value as many as possible.
            helper(i,target,sum + A[i],A,tmp,ans);
            tmp.pop_back();
        }
    }
}

vector<vector<int> > combinationSum(vector<int> &A, int B) {

    sort(A.begin(),A.end());
    vector<int> tmp;
    vector<vector<int>> ans;
    
    helper(0,B,0,A,tmp,ans);
    
    return ans;
  
}

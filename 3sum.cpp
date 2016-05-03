/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

FACEBOOK
GOOGLE

*/

vector<vector<int> >threeSum(vector<int> &A) 
{
        
        vector<vector <int>> ans;
         
    if(A.size() < 3)
        return ans;
        
        sort(A.begin(), A.end());
        
    int sum = -1;
        
        for(int i = 0; i < A.size() - 2; i++)
    {
                
        if(i > 0)
        {
                        
            if(A[i] == A[i - 1])
            {
                                
                continue;
                                
            }
                        
        }
                
                int j = i + 1;
                
        int k = A.size() - 1;
                
        vector<int> tmp;
                
        while(j < k)
        {
                        
                        sum = A[i] + A[j] + A[k];
                        
                        if(sum == 0)
                        {
                                
                                tmp.push_back(A[i]);
                                
                                tmp.push_back(A[j]);
                                
                                tmp.push_back(A[k]);
                                
                                ans.push_back(tmp);
                                
                                tmp.clear();
                                
                     
                                int num = A[j];
                                
                     
                                while(num == A[j])
                                        j++;
                                
                        }
                        
                        else if(sum < 0)
                        {
                                
                                j++;
                                
                        }
                        
                        else
                                k--;
                        
        }
    }
    return ans;      
}

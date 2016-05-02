/*

FACEBOOK/ GOOGLE 

Given n non-negative integers a1, a2, ..., an,
where each represents a point at coordinate (i, ai).
'n' vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).

Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Your program should return an integer which corresponds to the maximum area of water that can be contained ( Yes, we know maximum area instead of maximum volume sounds weird. But this is 2D plane we are working with for simplicity ).

*/

int Solution::maxArea(vector<int> &A) 
{

	int maxx = 0;
	int left = 0;
	int right = A.size() - 1;
	
	while(left < right)
	{
		
		maxx = max(maxx, ((right - left)*(min(A[left],A[right]))));
		
		if(A[left] < A[right])
			left++;
		
		else
			right--;
		
	}
	
        
	return maxx;
	
}

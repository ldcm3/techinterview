/* Merge k sorted linked lists and return it as one sorted list.

   Lucas Mendes

*/

// Definition for singly-linked list.

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

// Sort function for the priority_queue 
struct myfunc
{
	
    bool operator() (ListNode* p1, ListNode* p2)
		{
			
			return p1->val > p2->val;
			
		}
	
};

ListNode* mergeKLists(vector<ListNode*> &A) 
{
	
    
    
    ListNode* tail =  new ListNode(0);
    ListNode* head = tail;
	
    // Priority queue to store the list in descending order
    priority_queue<ListNode* , vector<ListNode*> , myfunc> queue;
    
    for(int i = 0; i < A.size(); i++)
    {
		if(A[i] != NULL)
			queue.push(A[i]);
    }
	    
	while(!queue.empty())
    {
		
        tail->next = queue.top();
        queue.pop();
		
		tail = tail->next;
		
		if(tail->next)
            queue.push(tail->next);
	}
	
	return head->next;
	
}






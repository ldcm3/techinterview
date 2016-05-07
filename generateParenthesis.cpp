*/    Generate all Parentheses 

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*n.

Facebook

Lucas Mendes

*/


void combinations(int A, int n_l, int n_r, vector<string> &c, string &s)
{
    if(n_l == A && n_r == A)
    {
        c.push_back(s);
        return;
    }
        
    if(n_r < A)
    {
        s += "(";
        combinations(A,n_l,n_r + 1, c, s);
        s.pop_back();
    }
    
    if(n_l < A && n_l < n_r)
    {
        s += ")";
        combinations(A,n_l + 1,n_r,c,s);
        s.pop_back();

    }
    

}


vector<string> generateParenthesis(int A) {

    vector<string> c;
    string s = "";
    
    combinations(A,0,0,c,s);
    
    return c;
}

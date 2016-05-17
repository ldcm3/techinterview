*/
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

FACEBOOK
AMAZON

Lucas Mendes


*/


// check if the substring is invalid such as: 01, 28 , 35 
bool check(string s1)
{
    
    if(s1[0] == '0')
        return false;
        
    int n = stoi(s1);
    
    if( n <= 26)
        return true;
    else
        return false;
}



int numDecodings(string A) {
   
    // Memoization
    int table[A.length() + 1];
    table[0] = 1;
    table[1] = 1;
    
    if(A.length() < 2 )
    {
        if(A[0] == '0')
            return 0;
        else
            return 1;
    }

    // if the first char is '0' no answer is possible
    if(A[0] == '0')
            return 0;
  
    for(int j = 1; j < A.length(); j++)
    {
        // if char is '0' and no combination such as "20" or "10" is possible
        if(A[j] == '0' && A[j - 1] != '1' && A[j - 1] != '2')
            return 0;
        else if(A[j] == '0')
            table[j] = table[j-1];
        else if(check(A.substr(j - 1, 2)))
            table[j] = table[j - 2] + table[j - 1];
        else
            table[j] = table[j - 1];
            
    }
        
        return table[A.length() - 1];
    
}

class Solution {
public:
    int minInsertions(string s) {

    int count =0;
    int result = 0; // no. of insertions 
    int i=0;

    while(i< s.size())
    {
        char ch = s[i];
        if(ch == '(')
        {
            count++;
            i++;
        }
        else{
            if(count > 0)
            {
                count--;   
            }
            else{
                result++;
            }

            if(i+1 < s.size() && s[i+1] == ')')
            {
                i +=2;
            }
            else{
                result ++;
                i += 1;
            }
        }
    }
    return result + 2*count ;

    
    }  
};
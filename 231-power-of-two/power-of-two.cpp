class Solution {
    
    bool ispower(int n, long long sum)
    {
        if(sum == n)
        {
            return true;
        }
        if (sum > n)
        {
            return false;
        }
        sum *= 2;
        return ispower(n,sum);
    }
public:
    bool isPowerOfTwo(int n) {
        
        if(n <= 0) return false ;
        long long  sum=1;
        return ispower(n, sum);
        
    }
};
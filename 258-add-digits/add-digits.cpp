class Solution {
    int single(int n)
    {
        if(n<10) return n;

        int sum=0;
        while(n)
        {
            sum = sum + n%10;
            n= n/10;
        }

        return single(sum);
    }
public:
    int addDigits(int num) {

        int ans = single(num);
        return ans ;
    }
};
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n= cardPoints.size();
        int lsum =0 , sum =0;
        for(int i=0; i< k; i++)
        {
            sum += cardPoints[i];
        }

        int maxSum = sum ;
        int l = k-1, r= n-1;

        while(r >= n-k)
        {
            sum -= cardPoints[l];
            l--;
            sum += cardPoints[r];
            r--;

            maxSum = max(maxSum, sum);
        }
        return maxSum; 
    }
};
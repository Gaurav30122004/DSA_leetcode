class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n= cardPoints.size();
        int lsum =0; 
        int rsum =0;
        for(int i=0; i< k; i++)
        {
            lsum += cardPoints[i];
        }

        int maxSum = lsum ;
        int r= n-1;

        for(int l= k-1; l>=0; l--)
        {
            lsum -= cardPoints[l];
            rsum += cardPoints[r];
            r--;

            maxSum = max(maxSum, lsum + rsum);
        }

        return maxSum; 
    }
};
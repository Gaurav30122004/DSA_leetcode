class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int rowCount = matrix.size();
        int colCount = matrix[0].size();
        int n = rowCount*colCount;
        int st=0;
        int end=n-1;

        int mid= st+(end-st)/2;

        while(st<=end)
        {
            int i = mid/colCount;         // we only require i and jth position  rest everything same as normal binary
            int j = mid% colCount;

            if(target ==  matrix[i][j])  // dont forget here elements are accessed usign [][] .
            {
                return true;
            }
            if(target <  matrix[i][j])
            {
                end = mid-1;
            }
            if(target > matrix[i][j])
            {
                st = mid+1;
            }
            mid= st+(end-st)/2;
        }
        return false;
    }
};
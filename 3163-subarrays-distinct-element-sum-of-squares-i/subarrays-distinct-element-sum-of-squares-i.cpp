#include <vector>
#include <unordered_set>

class Solution {
public:
    int sumCounts(std::vector<int>& nums) {
        int totalSum = 0;
        int n = nums.size();
        
        // Loop through every possible starting index of a subarray
        for (int i = 0; i < n; ++i) {
            std::unordered_set<int> distinctElements;
            
            // Expand the subarray to the right
            for (int j = i; j < n; ++j) {
                distinctElements.insert(nums[j]);
                
                // Get the current distinct count, square it, and add to sum
                int distinctCount = distinctElements.size();
                totalSum += distinctCount * distinctCount;
            }
        }
        
        return totalSum;
    }
};

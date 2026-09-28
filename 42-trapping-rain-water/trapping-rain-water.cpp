class Solution {
public:
    int trap(vector<int>& height) {
        
 int n = height.size();
        int ans = 0;
        int i = 0;

        while (i < n - 1) {
            int barrier = -1;

            // first bar on the right that is >= height[i]
            for (int j = i + 1; j < n; j++) {
                if (height[j] >= height[i]) {
                    barrier = j;
                    break;
                }
            }

            // none found: use the tallest bar on the right
            if (barrier == -1) {
                barrier = i + 1;
                for (int j = i + 1; j < n; j++) {
                    if (height[j] > height[barrier]) barrier = j;
                }
            }

            int level = min(height[i], height[barrier]);
            int between = 0;
            for (int k = i + 1; k < barrier; k++) between += height[k];

            ans += (barrier - i - 1) * level - between;
            i = barrier;   // jump, so no map is needed
        }
        return ans;
    }
};
class Solution {
public:
    int stoneGameVIII(std::vector<int>& stones) {
        int n = stones.size();
        
        // Step 1: Calculate prefix sums in-place to save memory
        for (int i = 1; i < n; ++i) {
            stones[i] += stones[i - 1];
        }
        
        // Step 2: DP from right to left
        // Base case: if we are at the last possible choice, we MUST take it.
        int ans = stones[n - 1]; 
        
        // We only go down to index 1 because x > 1 (must take at least 2 stones)
        for (int i = n - 2; i >= 1; --i) {
            ans = std::max(ans, stones[i] - ans);
        }
        
        return ans;
    }
};

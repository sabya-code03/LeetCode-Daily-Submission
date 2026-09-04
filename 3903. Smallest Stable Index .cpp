class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Step 1: Precompute the suffix minimums
        std::vector<int> suffix_min(n);
        suffix_min[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffix_min[i] = std::min(nums[i], suffix_min[i + 1]);
        }
        
        // Step 2 & 3: Track prefix max and evaluate instability
        int prefix_max = -1; // Safe initialization since nums[i] >= 0
        for (int i = 0; i < n; ++i) {
            prefix_max = std::max(prefix_max, nums[i]);
            
            // Step 4: Return the first index that satisfies the condition
            if (prefix_max - suffix_min[i] <= k) {
                return i;
            }
        }
        
        return -1;
    }
};

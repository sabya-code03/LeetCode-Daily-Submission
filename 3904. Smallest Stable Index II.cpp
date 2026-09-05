class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Step 1: Initialize an array to store the suffix minimums
        vector<int> suffix_min(n);
        suffix_min[n - 1] = nums[n - 1];
        
        // Populate the suffix_min array from right to left
        for (int i = n - 2; i >= 0; --i) {
            suffix_min[i] = min(suffix_min[i + 1], nums[i]);
        }
        
        int prefix_max = nums[0];
        
        // Step 2 & 3: Traverse left to right tracking the prefix maximum
        for (int i = 0; i < n; ++i) {
            prefix_max = max(prefix_max, nums[i]);
            
            // Step 4: Evaluate the condition instantly using the precomputed minimums
            if (prefix_max - suffix_min[i] <= k) {
                return i;
            }
        }
        
        // Return -1 if no stable index exists
        return -1;
    }
};
